#include <iostream>
#include <deque>
#include <list>

int main()
{
    std::list<int> list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> even_nums;
    std::deque<int> odd_nums;
    for (const auto &elem : list)
    {
        if (elem % 2)
            odd_nums.push_back(elem);
        else
            even_nums.push_back(elem);
    }
    for (const auto &elem : list)
        std::cout << elem << " ";
    std::cout << std::endl
              << "Even:" << std::endl;
    for (const auto &elem : even_nums)
        std::cout << elem << " ";
    std::cout << std::endl
              << "Odd:" << std::endl;
    for (const auto &elem : odd_nums)
        std::cout << elem << " ";
}