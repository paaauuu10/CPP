#include "Array.hpp"

template <typename T>
Array<T>::Array(){
    array = NULL;
    len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n){
    array = new T[n];
    len = n;
}

template <typename T>
Array<T>::Array(const Array &other){
    array = new T[other.len];
    len = other.len;
    for (unsigned int i = 0; i < other.len; i++)
        array[i] = other.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other){
    if (this != &other){
        if (len > 0)
            delete [] this->array;
        len = other.len;
        array = new T[other.len];
        for (unsigned int i = 0; i < other.len; i++)
            array[i] = other.array[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int position){
    if (position >= 0 && position < len)
        return array[position];
    throw std::range_error("Index out of bounds");
}

template <typename T>
Array<T>::~Array(){
    delete [] this->array;
}
		
template <typename T>
unsigned int Array<T>::size() const{
    return len;
}