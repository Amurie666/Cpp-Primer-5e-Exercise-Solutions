#include "Sales_data.h"
#include <vector>
#include <algorithm>

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    std::vector<Sales_data> sd;
    Sales_data trans;
    while (read(std::cin, trans))
        sd.push_back(trans);
    std::sort(sd.begin(), sd.end(), compareIsbn);
    for (const auto &elem : sd)
        print(std::cout, elem) << std::endl;
    while (true)
        ;
}