#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    // (a) Fixed using back_inserter. Though resize() could also be used to construct elements beforehand. The problem is that (a) attempts to assign to uninitialized vector.
    std::vector<int> vec;
    std::list<int> lst;
    int i;1 2
    while (std::cin >> i)
        lst.push_back(i);
    std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }

    // (b) Wrong. We should use resize() instead. Reserve only allocates 10 elements; we are still assigning to uninitialized memory.
}