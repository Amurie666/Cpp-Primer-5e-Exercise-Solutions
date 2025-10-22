#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

void store_file(std::ifstream &f, std::vector<std::string> &lines)
{
    std::string line;
    while (std::getline(f, line))
        lines.push_back(line);
}

int main()
{
    std::ifstream file("text.txt");
    std::vector<std::string> lines;
    store_file(file, lines);
    file.close();
    for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); it++)
    {
        std::istringstream line(*it);
        std::string word;
        while (line >> word)
            std::cout << word << " ";
        std::cout << std::endl;
    }
    char q;
    while (q != 'q' && q != 'Q')
        std::cin >> q;
}
