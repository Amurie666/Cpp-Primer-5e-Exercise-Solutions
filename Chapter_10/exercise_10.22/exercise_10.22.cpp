#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

bool longer_sx(const std::string &s, size_t sz)
{
    return s.size() > sz;
}

int main()
{
    std::vector<std::string> words = {"over", "the", "lazy", "dog", "therefore"};

    auto count = std::count_if(words.begin(), words.end(), std::bind(longer_sx, std::placeholders::_1, 6));

    std::cout << "Words longer than 6 characters: " << count << std::endl;

    return 0;
}
