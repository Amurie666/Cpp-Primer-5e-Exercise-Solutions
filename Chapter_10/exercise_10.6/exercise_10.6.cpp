#include <algorithm>
#include <iterator>
#include <iostream>
int main()
{
    int seq[5] = {1, 2, 3, 4, 5};
    std::fill_n(std::begin(seq), 5, 0);
    for (int i{0}; i != 5; i++)
        std::cout << seq[i] << " ";
}