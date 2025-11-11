#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}

void elimDups(std::vector<std::string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b)
                { return a.size() < b.size(); });
    auto wc = std::partition(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
    auto count = wc - words.begin();
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;
    for_each(words.begin(), wc, [](const std::string &s)
             { std::cout << s << " "; });
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word)
        words.push_back(word);
    biggies(words, 5);
}