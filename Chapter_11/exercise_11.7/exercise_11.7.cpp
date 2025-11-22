#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

int main()
{ // Using a set instead of a vector is better here.
    std::map<std::string, std::set<std::string>> fam_chldn;
    std::string line, fam_name, chld_name;
    std::cout << "Enter family and children names:" << std::endl;
    while (std::getline(std::cin, line))
    {
        std::istringstream names(line);
        names >> fam_name;
        std::set<std::string> children;
        while (names >> chld_name)
            fam_chldn[fam_name].insert(chld_name);
    }
    for (const auto &elem : fam_chldn)
    {
        std::cout << "Family: " << elem.first << ". Children: ";
        for (const auto &name : elem.second)
            std::cout << " " << name << "|";
        std::cout << std::endl;
    }
}