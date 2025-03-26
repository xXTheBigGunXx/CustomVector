#include "iterator.hpp"

template<typename T>
Iterator<T>::Iterator(T* ptr): _m_ptr(ptr) {}

template<typename T>
T& Iterator<T>::operator*() const {
    return *_m_ptr;
}

template<typename T>
T* Iterator<T>::operator->() const { 
    return _m_ptr; 
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() { 
    _m_ptr++; return *this;
} 

template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator<T> temp = *this; 
    ++(*this); 
    return temp;
}