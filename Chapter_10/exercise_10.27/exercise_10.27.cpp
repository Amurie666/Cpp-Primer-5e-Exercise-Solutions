#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::list<int> lst;

    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(lst));

    for (const auto &elem : lst)
        std::cout << elem << " ";
}