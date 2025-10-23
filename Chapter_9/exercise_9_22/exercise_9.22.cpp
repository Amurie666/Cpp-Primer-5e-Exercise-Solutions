#include <iostream>
#include <vector>
int main()
{
    /*
        Problems:
        While loop may be infinite depending on how iv and some_val are defined.
        Either or both of the iterators iter and mid may be invalidated during insertion.
    */
    // Fixed:
    int some_val = 3;
    std::vector<int> iv = {3, 7, 3, 9, 3, 1, 3, 3};
    std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
    while (iter != mid)
    {
        size_t dis = mid - iter;
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val) + 1;
            mid = (iter + dis);
        }
        iter++;
    }
    for (const auto &elem : iv)
        std::cout << elem << " ";
}