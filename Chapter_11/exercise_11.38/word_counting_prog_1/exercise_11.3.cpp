
#include <iostream>
#include "wrd.h"

int main()
{
    std::string f;
    std::cout << "\t\t Word Counting Program" << std::endl;
    std::cout << "\t Please enter file location and name: \n";
    std::cin >> f;
    std::ifstream file(f);
    std::unordered_map<std::string, size_t> word_count;
    wrd::count_word(file, word_count);
    wrd::display_count(word_count, std::cout);
    bool terminate = false;
    while (!terminate)
    {
        std::cin >> terminate;
    }
}
