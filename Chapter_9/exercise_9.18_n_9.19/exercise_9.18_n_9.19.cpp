#include <iostream>
#include <deque>
#include <list>

int main()
{
    // Exercise 9.18 and Exercise 9.19
    // For Exercise 9.19, simply change deque for list.
    std::string word;
    std::deque<std::string> text;
    while (std::cin >> word)
        text.push_back(word);
    for (std::deque<std::string>::iterator it = text.begin(); it != text.end(); ++it)
        std::cout << *it << " ";
    while (true)
        ;
}