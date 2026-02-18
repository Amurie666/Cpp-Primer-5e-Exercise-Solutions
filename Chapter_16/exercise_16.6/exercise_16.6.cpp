#include <vector>
#include <iostream>

// Similar to how we defined print earlier.

template<typename val_type, unsigned size>
val_type* begin(val_type (&arr)[size]) {
    if (size==0) return nullptr;
    return arr;
}

template<typename val_type, unsigned size>
val_type* end(val_type (&arr)[size]) {
    if (size==0) return arr;
    return arr+size;
}

int main() {
    int ar1[5] = {1, 2, 3, 4, 5};
    for(auto it = begin(ar1); it != end(ar1); it++) {
        std::cout << *it << std::endl;
    }
}