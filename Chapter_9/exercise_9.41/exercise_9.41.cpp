// Exercise 9.41
#include <vector>
#include <string>
#include <iostream>
int main()
{
    std::vector<char> vec = {'H', 'e', 'l', 'l', 'o', '.'};
    std::string hello(vec.cbegin(), vec.cend());
    std::cout << hello;
}
