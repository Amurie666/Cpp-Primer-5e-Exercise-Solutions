#include <numeric>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec_int = {1, 2, 3, 4, 5};
    int sum = std::accumulate(vec_int.begin(), vec_int.end(), 0);
    std::cout << sum << ". Checked: " << 1 + 2 + 3 + 4 + 5;
}