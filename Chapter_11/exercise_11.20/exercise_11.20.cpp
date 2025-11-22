#include <iostream>
#include <string>
#include <map>

int main()
{
    // The first version is easier to write but harder to read because insertion is hidden.
    // The second version is harder to write but easier to read.
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }
    for (const auto &w : word_count)
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << std::endl;
}