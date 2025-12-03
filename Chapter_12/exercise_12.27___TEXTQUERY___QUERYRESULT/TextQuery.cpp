#include "TextQuery.h"
#include "QueryResult.h"

#include <sstream>
TextQuery::TextQuery(std::ifstream& f) : fptr(new std::vector<std::string> ()) {
    std::string line;
    while (std::getline(f, line))
        fptr->push_back(line);
    std::string word;
    for(int index{0}; index<fptr->size(); index++) {
        std::istringstream read((*fptr)[index]);
        while(read >> word) {
            if(wrd_to_lines.find(word) == wrd_to_lines.end())
                wrd_to_lines[word] = std::make_shared<std::set<size_t>>();
            wrd_to_lines[word]->insert(index+1);
        }
    }
}

QueryResult TextQuery::query(std::string word) {
    auto qry = wrd_to_lines.find(word);
    if(qry != wrd_to_lines.end())
        return QueryResult(word, fptr, qry->second);
    return QueryResult(word, fptr, std::make_shared<std::set<size_t>>());
}