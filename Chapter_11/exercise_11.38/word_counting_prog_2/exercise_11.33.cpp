#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

// C++ Primer's version.

static std::unordered_map<std::string, std::string> word_abbrev;

void buildMap(std::ifstream &map_file)
{
    std::string key, val;
    while (map_file >> key && std::getline(map_file, val))
        if (val.size() > 1) // Do not register invalid lines.
            word_abbrev[key] = val.substr(1);
}

const std::string &transform(const std::string &s)
{
    // Calling this function on empty map simply does nothing except returning the original string, as we desire.
    auto it = word_abbrev.find(s);
    if (it != word_abbrev.end())
        return it->second;
    return s;
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
    std::string line, word;
    while (std::getline(input, line))
    {
        std::istringstream words(line);
        while (words >> word)
        {
            std::cout << transform(word);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
void decode(std::ifstream &map_file, std::ifstream &input)
{
    buildMap(map_file);
    word_transform(map_file, input);
}
int main()
{
    std::ifstream rules("rules.txt");
    std::ifstream input("input.txt");
    if (rules && input)
        decode(rules, input);
    else
        std::cerr << "Could not open file(s)." << std::endl;
}
