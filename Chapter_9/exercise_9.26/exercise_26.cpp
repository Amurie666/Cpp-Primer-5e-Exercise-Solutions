#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> vec(std::begin(ia), std::end(ia));
    std::list<int> list(std::begin(ia), std::end(ia));
    size_t size = sizeof(ia) / sizeof(ia[0]);
    auto it = vec.begin();
    auto il = list.begin();
    while (it != vec.end())
    {
        if (!(*it % 2))
            it = vec.erase(it);
        else
            ++it;
    }
    while (il != list.end())
    {
        if (*il % 2)
            il = list.erase(il);
        else
            ++il;
    }
    std::cout << "Odd:" << std::endl;
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "Even:" << std::endl;
    for (const auto &elem : list)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}