#include "vector.hpp"
#include "iterator.hpp"
#include <stdexcept>
#include <cstdint>
#include <iostream>

template<typename T>
xx::Vector<T>::Vector(): _capacity(1), _curr_index(0){
    _array = new T[_capacity];
}

template<typename T>
xx::Vector<T>::Vector(const size_t& length): _capacity(length), _curr_index(length)
{
    _array = new T[length];
}

template<typename T>
xx::Vector<T>::Vector(const size_t& length, const T& val): Vector(length)
{
    for(size_t i = 0; i < length; i++)
    {
        _array[i] = val;
    }
}

template<typename T>
xx::Vector<T>::Vector(std::initializer_list<T> list)
    : _capacity(list.size()), _curr_index(list.size()) {
    
    _array = new T[_capacity];

    size_t i = 0;
    for (const T& item : list) {
        _array[i++] = item;
    }
}

template<typename T>
xx::Vector<T>::~Vector(){ delete[] _array;}

template<typename T>
T& xx::Vector<T>::operator[](size_t index)
{
    if(index < 0 || index > _curr_index)
        throw std::invalid_argument("Index out of bounds!XX");
    else if (index == _curr_index)
    {
        extende();
        _curr_index++;
    }
    return _array[index];
}

template<typename T>
bool xx::Vector<T>::extende()
{
    size_t new_length = static_cast<size_t>(_capacity * _growth_factor);
    T* temp_arr = new T[new_length];

    for(size_t i = 0; i < _capacity; i++)
        temp_arr[i] = _array[i];
    delete[] _array;
    _capacity = new_length;
    _array = temp_arr;
    return true;
}

template<typename T>
bool xx::Vector<T>::extende(size_t new_size){
    if(new_size <= _capacity){
        std::cout << "New vector size is not big enought.\n";
        return false;
    }
    T* temp_arr = new T[new_size];

    for(size_t i = 0; i < _capacity; i++)
        temp_arr[i] = _array[i];
    delete[] _array;
    _capacity = new_size;
    _array = temp_arr;
    return true;    
}

template<typename T>
bool xx::Vector<T>::push_back(const T& val)
{
    if(_curr_index == _capacity)
        extende();
    _array[_curr_index++] = val;
    return true;
}

template<typename T>
bool xx::Vector<T>::change_growth_fac(const float& new_growth_fac)
{
    if(new_growth_fac <= 1 || new_growth_fac > _max_growth_factor)
        return false;
    _growth_factor = new_growth_fac;
    return true;
}

template<typename T>
bool xx::Vector<T>::loop_vector(void(*lambda)(T&))
{
    for(Iterator it = begin(); it != end(); it++){
        try{
            lambda(*it);
        } 
        catch(...){
            std::cout << "Failed to run the lambda function.\n";
            return false;
        }
    }
    return true;
}

template<typename T>
bool xx::Vector<T>::clear(){
    delete[] _array;
    _array = nullptr;
    _capacity = 0;
    _curr_index = 0;
    return true;
}