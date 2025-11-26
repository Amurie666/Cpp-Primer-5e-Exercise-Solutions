#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool read_lines(const std::string &name, std::vector<std::string> &content)
{
    std::ifstream inFile(name);
    if (inFile)
    {
        std::string line;
        while (std::getline(inFile, line))
        {
            content.push_back(line);
        }
        inFile.close();
        return true;
    }
    else
    {
        return false;
    }
}

int main() {
    std::vector<std::string> test_vec;
    std::string file;
    do {
    std::cout << "Enter file name or location:" << std::endl;
    std::cin >> file;
    if (read_lines(file, test_vec))
        for (const auto &elem : test_vec)
            std::cout << elem << std::endl;
    else
        std::cout << "Could not find file." << std::endl;
    } while (true);
}