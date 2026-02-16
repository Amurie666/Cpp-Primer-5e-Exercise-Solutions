#pragma once
#include "TextQuery.h"

class QueryResult
{
    friend class NotQuery;
    friend class OrQuery;
    friend class AndQuery;

public:
    QueryResult(
        const std::string &,
        std::shared_ptr<std::vector<std::string>>,
        std::shared_ptr<std::set<size_t>>);
    friend std::ostream &print(std::ostream &out, const QueryResult &);

private:
    std::string word;
    std::shared_ptr<std::vector<std::string>> fptr;
    std::shared_ptr<std::set<size_t>> lines;
};