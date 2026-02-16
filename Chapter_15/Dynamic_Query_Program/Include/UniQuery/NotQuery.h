#pragma once
#include "../QueryBase.h"
#include "WordQuery.h"

class NotQuery : public QueryBase
{
    friend Query operator~(const Query &op);

public:
    NotQuery(QueryBase *op);
    NotQuery(const NotQuery &op);
    NotQuery(NotQuery &&op) noexcept;
    NotQuery &operator=(const NotQuery &NQ);
    NotQuery &operator=(NotQuery &&NQ) noexcept;

    QueryResult evaluate() const override;
    std::string parameters() const override;

    ~NotQuery() { free(); }

private:
    void free();
    QueryBase *operand;
};