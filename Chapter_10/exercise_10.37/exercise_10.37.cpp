#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Vector:" << std::endl;
    for(const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::list<int> list(vec.rbegin()+2, vec.rend()-3);
    std::cout << "List:" << std::endl;
    for(const auto& elem : list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}