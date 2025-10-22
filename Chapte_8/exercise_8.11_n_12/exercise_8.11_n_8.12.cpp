#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <initializer_list>

struct PersonInfo
{
    /*  Exercise 8.12.
        We do not give in-class initializers here because the synthesized
        default constructor will default-initialize all data members. In addition, it is
        worth noting that for this class to be Aggregate, it need not ha-
        ve any in-class initializers. Hence, we could benefit from writi-
        ng code such as PersonInfo person = {\...\};
    */
    std::string name;
    std::vector<std::string> phones;
};

std::vector<PersonInfo> readInfo(std::ifstream &file)
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (std::getline(file, line))
    {   
        // We call std::istringstream::str() to re-bind record to a new string.
        // That said, it is important to call clear() on record before std::istringstream::str() so that bad, fail, and end of file bits 
        // of record all get reset back to default state before using record.
        record.clear();
        record.str(line);
        PersonInfo info;
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    return people;
}

void printPeopleInfo(const std::vector<PersonInfo> &people)
{
    for (const auto &person : people)
    {
        std::cout << person.name << std::endl;
        for (const auto &phone : person.phones)
        {
            std::cout << phone << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::string fileName;
    std::cout << "Enter file name: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    if (file)
    {
        const std::vector<PersonInfo> &people = readInfo(file);
        std::cout << "Registered:" << std::endl;
        printPeopleInfo(people);
    }
    else
    {
        std::cerr << "Error.";
    }
    file.close();
}