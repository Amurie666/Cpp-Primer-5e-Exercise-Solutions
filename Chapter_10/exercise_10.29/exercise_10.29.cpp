#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
// for print
#include <algorithm>
int main()
{
    std::vector<std::string> words;
    std::ifstream file("text.txt");
    std::istream_iterator<std::string> it(file), eof;
    while (it != eof)
        words.push_back(*it++);
    // print
    copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
}