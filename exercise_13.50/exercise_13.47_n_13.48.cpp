#include "String.h"
#include <iostream>
#include <vector>
#include <String>

int main() {
    std::cout << "Enter words." << std::endl;
    std::vector<String> vec;
    std::string word;
    while(std::cin >> word) {
        vec.push_back(word.c_str());
    }
    for(const auto& elem : vec) std::cout << elem << std::endl;
    std::cout << "If called, functions will appear here." << std::endl;
    while(true);
}