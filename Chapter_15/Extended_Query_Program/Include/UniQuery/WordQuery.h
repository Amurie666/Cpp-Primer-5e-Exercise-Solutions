#pragma once
#include "../QueryBase.h"
#include "../QueryResult.h"

class WordQuery : public QueryBase
{
public:
    WordQuery(std::string word) : operand(word)
    {
#ifdef TEST
        std::cout << "WordQuery(std::string word)" << std::endl;
#endif
    }
    QueryResult evaluate() const override;
    std::string parameters() const override;

private:
    const std::string operand;
};