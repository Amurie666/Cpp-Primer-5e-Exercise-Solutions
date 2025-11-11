#include <string>
#include <vector>
#include <iostream>
#include <functional>

bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}

int main()
{
    std::string word = "word";
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = std::find_if_not(vec.begin(), vec.end(), std::bind(check_size, word, std::placeholders::_1));
    if (it != vec.end())
        std::cout << *it;
}