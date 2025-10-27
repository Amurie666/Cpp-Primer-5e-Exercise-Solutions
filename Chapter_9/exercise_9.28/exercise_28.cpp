#include <iostream>
#include <forward_list>
#include <string>

bool insert_after(std::forward_list<std::string> &list,
                  const std::string &first,
                  const std::string &second)
{
    std::forward_list<std::string>::const_iterator prev = list.cbefore_begin();
    std::forward_list<std::string>::const_iterator curr = list.cbegin();
    bool found = false;
    while (curr != list.end())
    {
        if (*curr == first)
        {
            curr = list.insert_after(curr, second);
            found = true;
        }
        prev = curr++;
    }
    if (!found)
        list.insert_after(prev, second);
    return found;
}

int main()
{
    std::forward_list<std::string> test_vec = {"I", "Dedekind cuts.", "What", "about", "Do", "you", "Dedekind cuts"};
    insert_after(test_vec, "I", "love");
    insert_after(test_vec, "about", "you?");
    insert_after(test_vec, "you", "love");
    insert_after(test_vec, "Dedekind cuts", "too?");
    for (const auto &elem : test_vec)
        std::cout << elem << " ";
}