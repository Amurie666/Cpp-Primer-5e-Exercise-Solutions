#include <iostream>
#include <forward_list>

int main()
{
    // Though easy, this is a good exercise.
    std::forward_list<int> sample = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::forward_list<int>::const_iterator prev = sample.before_begin();
    std::forward_list<int>::iterator curr = sample.begin();
    std::cout << "Data: " << std::endl;
    for (const auto &elem : sample)
        std::cout << elem << " ";
    std::cout << std::endl;
    while (curr != sample.end())
    {
        if (*curr % 2)
            curr = sample.erase_after(prev);
        else
            prev = curr++;
    }
    std::cout << "Processed data: " << std::endl;
    for (const auto &elem : sample)
        std::cout << elem << " ";
}