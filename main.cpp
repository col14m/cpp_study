#include <algorithm>
#include <iostream>


#define LEN 10





template <typename T>
class my_vector
{
public:

    my_vector();
    my_vector(const my_vector& that);
    my_vector(size_t length);
    ~my_vector();

    T& operator[](size_t num) const;
    T& operator[](size_t num);

    const my_vector& operator=(const my_vector& that);
    size_t size() const
    {
        return length_;
    }

private:

    size_t length_;
    T* data_;

};

template <typename T>
my_vector<T>::my_vector():
    length_ (LEN),
    data_ (new T[LEN])
{

}

template <typename T>
my_vector<T>::my_vector(const my_vector& that):
    length_ (that.length_ ),
    data_ (new T[that.length_])
{

    std::copy(that.data_, that.data_ + that.length_, data_);
}
template <typename T>
my_vector<T>::~my_vector()
{
    length_ = 0;
    delete[] data_ ;
    data_ = nullptr;

}

template <typename T>
my_vector<T>::my_vector(size_t length):
    length_ (length),
    data_ (new T[length])
{


}
template <typename T>
my_vector<T> operator+(const my_vector<T>& va, const my_vector<T>& vb)
{

    my_vector<T> res(std::min(va.size(), vb.size()));
    for (size_t i = 0; i < std::min(va.size(), vb.size()); i++)
    {
        res[i] = va[i] + vb[i];
    }

    return res;
}

template <typename T>
my_vector<T> operator-(const my_vector<T>& va, const my_vector<T>& vb)
{

    my_vector<T> res(std::min(va.size(), vb.size()));
    for (size_t i = 0; i < std::min(va.size(), vb.size()); i++)
    {
        res[i] = va[i] - vb[i];
    }

    return res;
}

template <typename T>
T& my_vector<T>::operator[](size_t num) const
{
    return data_[num];

}

template <typename T>
T& my_vector<T>::operator[](size_t num)
{
    return data_[num];

}



template <typename T>
const my_vector<T>& my_vector<T>::operator=(const my_vector& that)
{

    if (this == &that) return that;

    my_vector victim(that);
    std::swap(length_, victim.length_);
    std::swap(data_, victim.data_);

    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const my_vector <T>& v)
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

    my_vector<int> a = 5;
    my_vector <int> b;
    for (int i = 0; i < 5; i++){
        a[i] = i;
    }
    b = a;

    my_vector<int > c = a - b ;
    std::cout << a;
    return 0;
}
