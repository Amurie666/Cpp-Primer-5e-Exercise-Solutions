#include "../Include/TextQuery.h"
#include "../Include/QueryResult.h"

#include <sstream>
TextQuery::TextQuery(std::ifstream &f) : fptr(new std::vector<std::string>())
{
    std::string line;
    while (std::getline(f, line))
        fptr->push_back(line);
    std::string word;
    for (int index{0}; index < fptr->size(); index++)
    {
        std::istringstream read((*fptr)[index]);
        while (read >> word)
        {
            if (wrd_to_lines.find(word) == wrd_to_lines.end())
                wrd_to_lines[word] = std::make_shared<std::set<size_t>>();
            wrd_to_lines[word]->insert(index + 1);
        }
    }
#ifdef TEST
    std::cout << "TextQuery::TextQuery(std::ifstream& f)" << std::endl;
#endif
}

QueryResult TextQuery::query(std::string word) const
{
    auto qry = wrd_to_lines.find(word);
    if (qry != wrd_to_lines.end())
        return QueryResult(word, fptr, qry->second);
    return QueryResult(word, fptr, std::make_shared<std::set<size_t>>());
}