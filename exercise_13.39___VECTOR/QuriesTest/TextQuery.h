 #pragma once 
 #include "Vector.h"
 #include <map>
 #include <set>
 #include <memory>
 #include <string>
#include <fstream>
#include<iostream>

class QueryResult;
class TextQuery {
    friend class QueryResult;
    public:
    TextQuery(std::ifstream&);
    QueryResult query(std::string word);
    private:
    std::shared_ptr<Vector<std::string>> fptr;
    std::map<std::string, std::shared_ptr<std::set<size_t>>> wrd_to_lines;
};
