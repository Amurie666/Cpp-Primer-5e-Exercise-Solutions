#include <vector>
#include <iostream>

std::vector<int> *const print(std::vector<int> *const vecp)
{ // Same.
    std::cout << "The passed vector is: ";
    for (auto it = vecp->begin(); it != vecp->end(); it++)
        std::cout << *it << " ";
    return vecp;
}

std::vector<int> *const read(std::vector<int> *const vecp)
{ // Accepts and returns a const pointer as both a promise and to ensure that the memory is never lost.
    int x;
    std::cout << "Enter vector elements: ";
    while (std::cin >> x)
        vecp->push_back(x);
    std::cout << std::endl;
    return vecp;
}

std::vector<int> *const vec_alloc()
{ // Returns a const pointer to ensure that the memory is never lost.
    return new std::vector<int>;
}

int main()
{

    std::vector<int> *vecp = vec_alloc();
    print(read(vecp));
    delete vecp;
    vecp = nullptr;
    // vecp should not be std::vector<int> *const for this to work.
    // No delegating pointers are preserved because the pointer returned by vec_alloc() is destroyed by default.
    return 0;
}