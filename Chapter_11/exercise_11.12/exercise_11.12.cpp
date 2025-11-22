#include <string>
#include <vector>
#include <utility>
#include <iostream>

int main()
{
    std::vector<std::pair<std::string, int>> pairs;
    std::string x;
    int y;
    while (std::cin >> x >> y)
        // pairs.push_back({x, y}): has the same effect as make_pair
        // pairs.emplace_back(x, y) constructs the object in place, which is more efficient.
        pairs.push_back(std::make_pair(x, y));
    for (const auto &elem : pairs)
        std::cout << elem.first << " " << elem.second << std::endl;
    return 0;
}