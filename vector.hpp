#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "stddef.h"
#include "iterator.hpp"
#include <initializer_list>

namespace xx
{
    template<typename T>
    class Vector
    {
    private:
        T* _array = nullptr;
        size_t _curr_index;
        float _growth_factor = 2.0f;
        const float _max_growth_factor = 10.0f;
    public:
        size_t _capacity;
        Iterator<T> begin() { return Iterator(_array); }
        Iterator<T> end() { return Iterator(_array + _curr_index); }

        Vector();
        Vector(const size_t& length);
        Vector(const size_t& length, const T& val);
        template<size_t N>
        Vector(const T (&array_to_copy)[N]): _capacity(N), _curr_index(N){
            _array = new T[N];
            for(size_t i = 0; i < N; i++)
                _array[i] = array_to_copy[i];
        }
        Vector(std::initializer_list<T> list);
        ~Vector();
        T& operator[](size_t index);
        bool extende();
        bool extende(size_t new_size);
        bool push_back(const T& val);
        bool change_growth_fac(const float& new_growth_fac);
        bool loop_vector(void(*lambda)(T&));
        bool clear();
    };
}

#include "vector.tpp"

#endif