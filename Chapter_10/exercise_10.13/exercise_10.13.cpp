#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

bool is_five_or_more(const std::string &s)
{
    return s.size() >= 5;
}

int main()
{
    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word)
        words.push_back(word);
    std::partition(words.begin(), words.end(), is_five_or_more);
    for (const auto &elem : words)
        std::cout << elem << " ";
}