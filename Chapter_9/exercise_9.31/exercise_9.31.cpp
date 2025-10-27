/*
    Does not work on list because the operator += in line 7 is not defined for a list.
    Does not work on forward_list because the operator += in line 7, along with the operations
    insert and erase, are not defined for a forward list. A forward list cannot insert before an element.
*/
#include <vector>
#include <iostream>
#include <list>
#include <forward_list>
using namespace std; // Not usually my style but could simplify things a lot.

void use_frd_list()
{
    forward_list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = vi.cbefore_begin();
    auto iter = vi.cbegin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            vi.insert_after(prev, *iter); // duplicate the current element
            prev = iter;
            ++iter; // advance past this element and the one inserted before it
        }
        else
            iter = vi.erase_after(prev); // remove even elements
        // don’t advance the iterator; iter denotes the element after the one we erased
    }
    for (const auto &elem : vi)
        std::cout << elem << " ";
}
void use_list()
{
    list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.cbegin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter); // duplicate the current element
            ++iter;
            ++iter; // advance past this element and the one inserted before it
        }
        else
            iter = vi.erase(iter); // remove even elements
        // don’t advance the iterator; iter denotes the element after the one we erased
    }
    for (const auto &elem : vi)
        std::cout << elem << " ";
}
int main()
{
    use_frd_list();
    cout << endl;
    use_list();
}