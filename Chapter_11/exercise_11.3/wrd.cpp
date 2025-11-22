#include "wrd.h"

void wrd::minimize_word(std::string &word)
{
    std::string punc = ",.;'`\":{}[]()—–";
    for (size_t i{0}; i != word.size(); i++)
    {
        if (punc.find(word[i]) != std::string::npos)
        {
            word.erase(i, 1);
            --i;
        }
    }
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
}
void wrd::count_word(std::ifstream &file, std::map<std::string, size_t> &word_count)
{
    std::string word;
    while (file >> word)
    {
        minimize_word(word);
        ++word_count[word];
    }
}
void wrd::display_count(std::map<std::string, size_t> &word_count, std::ostream &out)
{
    for (const auto &w : word_count)
        out << "\t The word \"" << w.first << "\" appears " << w.second << ((w.second == 1) ? " time." : " times.") << std::endl;
    ;
}