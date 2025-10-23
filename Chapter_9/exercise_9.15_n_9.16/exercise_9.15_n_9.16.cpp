#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// Exercise 9.16
bool is_equal(const std::list<int> &z, const std::vector<int> &x)
{
    if (x.size() != z.size())
        return false;
    for (const auto &a : z)
        if (std::find(x.begin(), x.end(), a) == x.end())
            return false;
    return true;
}

int main()
{
    // Exercise 9.15
    std::vector<int> x = {1, 2, 5, 7};
    std::vector<int> y = {1, 2};
    std::cout << "Exercise 9.15. Checked: " << ((x == y) ? "equal." : "not equal.") << std::endl;
    // Exercise 9.16
    std::list<int> z = {1, 2, 5, 7};
    std::cout << "Exercise 9.16. Checked: " << (is_equal(z, x) ? "equal." : "not equal.") << std::endl;
}