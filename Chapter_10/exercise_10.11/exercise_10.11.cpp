#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

void print(const std::vector<std::string> &vec)
{
    for (const auto &elem : vec)
        std::cout << elem << " ";
    std::cout << std::endl;
}

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

void elim_dups(std::vector<std::string> &vec)
{
    std::sort(vec.begin(), vec.end());
    auto end_of_unique = std::unique(vec.begin(), vec.end());
    vec.erase(end_of_unique, vec.end());
}
int main()
{
    std::vector<std::string> line;
    std::string word;
    while (std::cin >> word)
        line.push_back(word);
    elim_dups(line);
    print(line);
    stable_sort(line.begin(), line.end(), isShorter);
    print(line);
}