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
        // We can't use find() here because the operator== compares all members of two Sales_item objects, which is not what we need.
        auto lst_occur = std::find_if(items.rbegin(), items.rend(), 
        [&it] (const Sales_item& itm) 
        { return compareIsbn(itm, *it); }).base();
        auto sum = std::accumulate(it, lst_occur, Sales_item(it->isbn()));
        total.push_back(sum);
        it = lst_occur;
    }
    for (const auto &elem : total)
    {
        writer = elem;
        std::cout << std::endl;
    }
    return 0;
}
