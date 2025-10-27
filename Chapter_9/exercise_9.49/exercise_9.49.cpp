#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    std::string result;
    std::ifstream in_file;
    std::string file_nme;
    std::string ascenders_n_descenders = "bdfhkltgjpqy";
    do
    {
        std::cout << "Please enter file name: ";
        std::cin >> file_nme;
        in_file.open(file_nme);
    } while (!in_file);
    std::string word;
    while (in_file >> word)
        if (word.find_first_of(ascenders_n_descenders) == std::string::npos && word.size() > result.size())
            result = word;
    std::cout << "The longest word in the file that contains neither ascenders nor descenders: " << result << std::endl;
}