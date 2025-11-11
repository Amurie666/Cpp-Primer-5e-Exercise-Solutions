#include <list>
#include <iostream>
#include <algorithm>

int main()
{
    std::list<int> list = {1, 2, 0, 4, 5, 3, 10, 4, 0, 2, 3};
    auto it = std::find(list.rbegin(), list.rend(), 0);
    if (it == list.rend())
        std::cout << "No such element exists.";
    else
    {
        auto b_it = (++it).base();
        std::cout << "Element found: " << *b_it;
    }
    return 0;
}