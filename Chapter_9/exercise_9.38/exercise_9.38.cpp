#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> vec;
    std::string line;
    while (true)
    {
        std::cout << "Vector Size: " << vec.size() << ". Vector Capacity: " << vec.capacity() << std::endl;
        std::cout << "Enter a new line to store: " << std::endl;
        std::getline(std::cin, line);
        vec.push_back(line);
    }
}