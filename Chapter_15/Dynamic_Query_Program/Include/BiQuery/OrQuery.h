#pragma once
#include "BiQuery.h"
#include <algorithm>

class OrQuery : public BiQuery
{
    friend Query operator|(const Query &lhs, const Query &rhs);
    using BiQuery::BiQuery;
    QueryResult evaluate() const override;
    std::string parameters() const override;
};