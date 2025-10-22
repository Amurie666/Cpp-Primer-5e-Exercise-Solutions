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
        std::cout << person.name << ": ";
        for (const auto &phone : person.phones)
        {
            std::cout << phone << " ";
        }
        std::cout << std::endl;
    }
}


bool valid(const std::string& num) { return (num.size() == 9) && (num.find_first_not_of("0123456789") == std::string::npos); }
std::string format(const std::string& num) {
    return num.substr(0, 3) + "-" + num.substr(3, 3) + "-" + num.substr(6);
}
std::ostream &checkNums(const std::vector<PersonInfo> &people, std::ostream &result)
{
    /*
        Exercise 8.14
        The variables entry and nums are const auto& because they are read-only use;
        we need neither modify nor copy them.
    */
    for (const auto &entry : people)
    {
        std::string name = entry.name;
        std::cout << "Check " << name << ":" << std::endl;
        std::ostringstream formatted, badNums;
        for (const auto &num : entry.phones)
        {
            if (!valid(num))
            {
                badNums << num << std::endl;
            }
            else
            {
                formatted << format(num) << std::endl;
            }
        }
        result << "Formatted Numbers:" << std::endl;
        result << formatted.str() << std::endl;
        result << "Bad Numbers:" << std::endl;
        result << badNums.str() << std::endl;
    }
    return result;
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
        std::cout<<std::endl;   
        checkNums(people, std::cout);
    }
    else
    {
        std::cerr << "Error.";
    }
    file.close();
}