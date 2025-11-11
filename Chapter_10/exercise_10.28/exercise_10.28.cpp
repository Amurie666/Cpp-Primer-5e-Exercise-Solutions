#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vc;
    std::list<int> lst;
    std::deque<int> deq;
    std::copy(vec.begin(), vec.end(), std::back_inserter(vc));
    std::copy(vec.begin(), vec.end(), std::front_inserter(deq));
    std::copy(vec.begin(), vec.end(), std::inserter(lst, lst.begin()));
    for (const auto &elem : vc)
        std::cout << elem << " ";
    std::cout << std::endl;
    for (const auto &elem : lst)
        std::cout << elem << " ";
    std::cout << std::endl;
    for (const auto &elem : deq)
        std::cout << elem << " ";
    std::cout << std::endl;
}