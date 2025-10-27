#include <iostream>
#include <vector>

int main()
{
    // Assuming the body is intended to be a block, this loop wrongfully attempts to duplicate the odd values of iv.
    // The loop is wrong because if the container contains an odd value, it will execute indefinitely (since it never
    // moves to the next element to check whether it should be duplicated.
    // The following is a fix:
    std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            ++iter;
        }
        ++iter;
    }
    for (const auto &elem : vi)
        std::cout << elem << " ";
}