#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

template<typename T>
struct Iterator
{    
    Iterator(T* ptr);
    T& operator*() const;
    T* operator->() const;
    Iterator& operator++();
    Iterator operator++(int);
    friend bool operator==(const Iterator<T>& a, const Iterator<T>& b) { 
        return a._m_ptr == b._m_ptr; 
    }
    friend bool operator!=(const Iterator<T>& a, const Iterator<T>& b) { 
        return !(a == b); 
    }    
private:
    T* _m_ptr;
};

#include "iterator.tpp"
#endif