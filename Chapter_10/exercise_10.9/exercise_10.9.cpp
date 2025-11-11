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

void elim_dups(std::vector<std::string> &vec)
{
    std::sort(vec.begin(), vec.end());
    // print(vec);
    auto end_of_unique = std::unique(vec.begin(), vec.end());
    // print(vec);
    vec.erase(end_of_unique, vec.end());
    // print(vec);
}
int main()
{
    std::vector<std::string> line;
    std::string word;
    while (std::cin >> word)
        line.push_back(word);
    elim_dups(line);
    print(line);
}