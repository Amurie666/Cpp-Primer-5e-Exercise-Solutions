#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> vec = {"going?", "it", "How's", "there!", "Hello"};
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
        std::cout << *it << " ";
    return 0;
}