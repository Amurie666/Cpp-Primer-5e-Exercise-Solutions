 #pragma once 

#include "TextQuery.h"

class QueryResult {
    public:
    QueryResult(
        const std::string&, 
        std::shared_ptr<Vector<std::string>>, 
        std::shared_ptr<std::set<size_t>>
    );
    friend std::ostream& print(std::ostream& out, const QueryResult&);
    private: 
    std::string word;
    std::shared_ptr<Vector<std::string>> fptr;
    std::shared_ptr<std::set<size_t>> lines;
};