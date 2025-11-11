#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> vec = {"going?", "it", "How's", "there!", "Hello"};
    for (auto it = vec.end(); it != vec.begin();)
        std::cout << *(--it) << " ";
    return 0;
}