#include <iostream>
#include <vector>

bool exists(std::vector<int>::iterator beg, std::vector<int>::iterator end, int x)
{
    while (beg != end)
    {
        if (*beg == x)
            return true;
        ++beg;
    }
    return false;
}

// Exercise 9.5 -
std::vector<int>::iterator
find(std::vector<int>::iterator beg, std::vector<int>::iterator end, int x)
{
    while (beg != end)
    {
        if (*beg == x)
            return beg; // Return the iterator bound to x if x was found.
        ++beg;
    }
    return end; // Otherwise, return end.
}
// -

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    std::cout << "The number 5 " << (exists(vec.begin(), vec.end(), 5) ? "exists" : " does not exist") << " in vec." << std::endl;
    std::cout << "The number 5 " << (find(vec.begin(), vec.begin() + 3, 5) != vec.begin() + 3 ? "exists" : " does not exist") << " in [" << *vec.begin() << ", " << *(vec.begin() + 3) << ")  of vec." << std::endl;
}