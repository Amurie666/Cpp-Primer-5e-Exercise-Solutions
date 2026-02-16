#pragma once
#include "../QueryBase.h"
#include "../TextQuery.h"

class BiQuery : public QueryBase
{
protected:
    BiQuery(QueryBase *lhs, QueryBase *rhs);
    BiQuery(const BiQuery &BQ);
    BiQuery &operator=(const BiQuery &BQ);
    BiQuery(BiQuery &&BQ) noexcept;
    BiQuery &operator=(BiQuery &&BQ) noexcept;

    virtual QueryResult evaluate() const = 0;
    virtual std::string parameters() const = 0;

    virtual ~BiQuery() { free(); }
    QueryBase *operand1;
    QueryBase *operand2;

private:
    void free();
    void free(QueryBase *op);
};