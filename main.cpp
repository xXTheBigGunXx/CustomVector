#include "vector.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

int main()
{
    xx::Vector<int> vec = {1,2,3,4,5};
    auto print = [](int& i) { std::cout << i << '\n';};
    
    vec.loop_vector(print);
}