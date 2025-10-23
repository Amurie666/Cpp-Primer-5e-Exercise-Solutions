#include <iostream>
#include <vector>
#include <string>
#include <list>

void copy(const std::list<const char *> &list, std::vector<std::string> &vec)
{
    vec.assign(list.cbegin(), list.cend());
}

int main()
{
    std::list<const char *> list{"hello", "there!"};
    std::vector<std::string> vec;
    copy(list, vec);
    for (const auto &elem : vec)
        std::cout << elem << " ";
    while (true)
        ;
}
