#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Sales_item.h"

int main()
{
    std::istream_iterator<Sales_item> reader(std::cin), eof;
    std::ostream_iterator<Sales_item> writer(std::cout);
    std::vector<Sales_item> items(reader, eof);
    std::vector<Sales_item> total;
    std::sort(items.begin(), items.end(), compareIsbn);
    for (auto it = items.begin(); it != items.end();)
    {
        // We cannot use find() here because the operator== compares all members of two Sales_data objects, which is not what we need.
        // However, as a solution, we temporarily modified operator==(const Sales_item &lhs, const Sales_item &rhs).
        auto lst_occur = std::find(items.rbegin(), items.rend(), *it).base();
        auto sum = std::accumulate(it, lst_occur, Sales_item(it->isbn()));
        total.push_back(sum);
        it = ++lst_occur;
    }
    for (const auto &elem : total)
    {
        writer = elem;
        std::cout << std::endl;
    }
    return 0;
}
