#include <algorithm>
#include <iostream>


#define LEN 10





template <typename T>
class super_vector
{
public:

    super_vector();
    super_vector(const super_vector& that);
    super_vector(size_t length);
    ~super_vector();

    T& operator[](size_t num) const;
    T& operator[](size_t num);

    const super_vector& operator=(const super_vector& that);
    size_t size() const
    {
        return length_;
    }

private:

    size_t length_;
    T* data_;

};

template <typename T>
super_vector<T>::super_vector():
    length_ (LEN),
    data_ (new T[LEN])
{

}

template <typename T>
super_vector<T>::super_vector(const super_vector& that):
    length_ (that.length_ ),
    data_ (new T[that.length_])
{

    std::copy(that.data_, that.data_ + that.length_, data_);
}
template <typename T>
super_vector<T>::~super_vector()
{
    length_ = 0;
    delete[] data_ ;
    data_ = nullptr;

}

template <typename T>
super_vector<T>::super_vector(size_t length):
    length_ (length),
    data_ (new T[length])
{


}
template <typename T>
super_vector<T> operator+(const super_vector<T>& va, const super_vector<T>& vb)
{

    super_vector<T> res(std::min(va.size(), vb.size()));
    for (size_t i = 0; i < std::min(va.size(), vb.size()); i++)
    {
        res[i] = va[i] + vb[i];
    }

    return res;
}

template <typename T>
super_vector<T> operator-(const super_vector<T>& va, const super_vector<T>& vb)
{

    super_vector<T> res(std::min(va.size(), vb.size()));
    for (size_t i = 0; i < std::min(va.size(), vb.size()); i++)
    {
        res[i] = va[i] - vb[i];
    }

    return res;
}

template <typename T>
T& super_vector<T>::operator[](size_t num) const
{
    return data_[num];

}

template <typename T>
T& super_vector<T>::operator[](size_t num)
{
    return data_[num];

}



template <typename T>
const super_vector<T>& super_vector<T>::operator=(const super_vector& that)
{

    if (this == &that) return that;

    super_vector victim(that);
    std::swap(length_, victim.length_);
    std::swap(data_, victim.data_);

    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const super_vector <T>& v)
{
    size_t i = 0;
    for (i; i + 1 < v.size(); i++)
    {
        out << v[i] << ' ';

    }
    out << v[i] ;
    return out;


}



int main (){

    super_vector<int> a = 5;
    super_vector <int> b;
    for (int i = 0; i < 5; i++){
        a[i] = i;
    }
    b = a;

    super_vector<int > c = a - b ;
    std::cout << a;
    return 0;
}
