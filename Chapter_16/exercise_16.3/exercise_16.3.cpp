#include <string>
#include <iostream>
#include "Sales_data.h"

template <typename T>
bool compare(const T &lhs, const T &rhs)
{
    std::cerr << "CALLED template<typename T> bool compare(const T& lhs, const T& rhs)" << std::endl;
    return lhs < rhs;
}


int main()
{
    Sales_data item1, item2;
    compare(item1, item2);
    /*
        Error:  error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data').
    */
}