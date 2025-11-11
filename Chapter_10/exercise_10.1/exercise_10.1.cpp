#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> seq;
    std::vector<int> read;
    std::cout << "Reading..." << std::endl;
    int data;
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
