#pragma once
#include "BiQuery.h"
#include "algorithm"

class AndQuery : public BiQuery
{
    using BiQuery::BiQuery;
    QueryResult evaluate() const override;
    std::string parameters() const override;
};