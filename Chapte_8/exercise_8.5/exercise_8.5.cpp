#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool read_words(const std::string &name, std::vector<std::string> &content)
{
    std::ifstream inFile(name);
    if (inFile)
    {
        std::string word;
        while (inFile >> word)
        {
            content.push_back(word);
        }
        inFile.close();
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::vector<std::string> test_vec;
    std::string file;
    do {
    std::cout << "Enter file name or location:" << std::endl;
    std::cin >> file;
    if (read_words(file, test_vec))
        for (const auto &elem : test_vec)
            std::cout << elem << std::endl;
    else
        std::cout << "Could not find file." << std::endl;
    } while (true);
}