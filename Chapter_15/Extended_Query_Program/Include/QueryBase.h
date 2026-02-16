#pragma once
#include "TextQuery.h"
#include "QueryResult.h"
#include <memory>

class QueryBase
{
    friend void read(const std::string directory);

public:
    virtual QueryResult evaluate() const = 0;
    virtual std::string parameters() const = 0;
    virtual ~QueryBase() {}

protected:
    static std::unique_ptr<TextQuery> TextFile;
};

void read(const std::string directory);
