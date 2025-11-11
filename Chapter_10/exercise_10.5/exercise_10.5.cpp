#include <vector>
#include <iostream>

int main()
{
    std::vector<const char *> v1 = {"Hi", "Good", "Bad"};
    std::vector<const char *> v2 = {"Hello", "Gift", "Brain"};
    std::cout << "v1: ";
    for (const auto &elem : v1)
        std::cout << elem << " ";
    std::cout << std::endl;
    std::cout << "v2: ";
    for (const auto &elem : v2)
        std::cout << elem << " ";
    std::cout << std::endl;
    std::cout << "The two vectors are " << (std::equal(v1.cbegin(), v1.cbegin(), v2.cbegin()) ? "equal." : "not equal.");
    return 0;
}