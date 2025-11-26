#include <memory>
#include <vector>
#include <iostream>

// More compact.

std::shared_ptr<std::vector<int>> print(std::shared_ptr<std::vector<int>> vecp)
{
    std::cout << "The passed vector is: ";
    for (auto it = vecp->begin(); it != vecp->end(); it++)
        std::cout << *it << " ";
    return vecp;
}

std::shared_ptr<std::vector<int>> read(std::shared_ptr<std::vector<int>> vecp)
{
    int x;
    std::cout << "Enter vector elements: ";
    while (std::cin >> x)
        vecp->push_back(x);
    std::cout << std::endl;
    return vecp;
}

std::shared_ptr<std::vector<int>> vec_alloc()
{ // Shared_ptr need not be const because the underlying object is destroyed once reference count goes to 0.
    return std::make_shared<std::vector<int>>();
}

int main()
{

    std::shared_ptr<std::vector<int>> vecp = vec_alloc();
    print(read(vecp));
    return 0;
}