#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <fstream>

int main()
{
    std::map<std::string, std::set<size_t>> wrd_to_lines;
    std::vector<std::string> file;
    std::ifstream infile;
    std::string file_nme;
    std::string text;
    while (!infile.is_open())
    {
        std::cout << "Please enter file name: ";
        std::cin >> file_nme;
        infile.open(file_nme);
    }
    int ind = 1;
    std::cout << "Preparing File..." << std::endl;
    while (std::getline(infile, text))
    {
        file.push_back(text);
        std::string word;
        std::istringstream s(text);
        while (s >> word)
        {
            if (wrd_to_lines.find(word) == wrd_to_lines.end())
                wrd_to_lines[word] = std::set<size_t>();
            wrd_to_lines[word].insert(ind);
        }
        ++ind;
    }
    std::string word;
    while (true)
    {
        std::cout << "Enter a word to look for, or q to quit: ";
        if (!(std::cin >> word) || word == "q")
            break;
        if (wrd_to_lines.find(word) == wrd_to_lines.end())
            std::cout << "The word " << "\"" << word << "\"" << " appears 0 times." << std::endl;
        else
        {
            std::cout << "The word " << "\"" << word << "\"" << " appears " << wrd_to_lines[word].size() << (wrd_to_lines[word].size() == 1 ? " time." : " times.") << std::endl;
            for (const auto &elem : wrd_to_lines[word])
                std::cout << "\t (line " << elem << ") " << file[elem - 1] << std::endl;
        }
    }
}