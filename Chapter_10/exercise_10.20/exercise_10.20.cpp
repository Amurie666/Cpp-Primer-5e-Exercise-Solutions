#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> words = {"over", "the", "lazy", "dog", "therefore"};

    auto count = std::count_if(words.begin(), words.end(),
                               [](const std::string &s)
                               {
                                   return s.size() > 6;
                               });

    std::cout << "Words longer than 6 characters: " << count << std::endl;

    return 0;
}