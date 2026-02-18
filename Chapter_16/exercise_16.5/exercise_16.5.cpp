#include <iostream>

template<typename val_type, unsigned size>
void print(const val_type (&arr)[size]) {
    for(size_t i{0}; i != size; ++i)
        std::cout << arr[i] << std::endl;  
}