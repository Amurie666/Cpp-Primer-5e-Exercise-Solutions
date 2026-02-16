#pragma once
#include "../QueryBase.h"
#include "../QueryResult.h"

// WordQuery can rely on synthesized copy-control members.

class WordQuery : public QueryBase
{
public:
    WordQuery(std::string word) : operand(word) {}
    QueryResult evaluate() const override;
    std::string parameters() const override;

private:
    const std::string operand;
};