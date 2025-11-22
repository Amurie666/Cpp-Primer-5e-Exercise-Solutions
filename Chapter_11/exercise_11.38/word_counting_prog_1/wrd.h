#include <unordered_map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <algorithm>

namespace wrd
{
    void minimize_word(std::string& word);
    void count_word(std::ifstream &file, std::unordered_map<std::string, size_t> &word_count);
    void display_count(std::unordered_map<std::string, size_t> &word_count, std::ostream &out);
}