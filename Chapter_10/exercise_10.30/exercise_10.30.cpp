#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

int main()
{
    std::istream_iterator<int> init(std::cin), eof;
    std::vector<int> vec(init, eof);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}
