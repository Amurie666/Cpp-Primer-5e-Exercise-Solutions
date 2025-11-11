#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<std::string> seq;
    std::list<std::string> read;
    std::cout << "Reading..." << std::endl;
    std::string data;
    while (std::cin >> data)
        seq.push_back(data);
    for (const auto &elem : seq)
    {
        if (std::find(read.begin(), read.end(), elem) == read.end())
        {
            std::cout << "The value " << elem << " appears " << std::count(seq.begin(), seq.end(), elem) << std::endl;
            read.push_back(elem);
        }
    }
    return 0;
}