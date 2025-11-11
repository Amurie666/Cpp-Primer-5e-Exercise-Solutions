#include <list>
#include <string>
#include <iostream>

void elimDups(std::list<std::string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    std::list<std::string> test = {"E", "A", "B", "C", "D", "E", "E", "F", "G", "A", "H", "E", "I", "J", "E", "K"};
    for (const auto &elem : test)
        std::cout << elem << " ";
    std::cout << std::endl;
    elimDups(test);
    std::cout << "After calling elimDups(std::list<std::string> &words):" << std::endl;
    for (const auto &elem : test)
        std::cout << elem << " ";
}