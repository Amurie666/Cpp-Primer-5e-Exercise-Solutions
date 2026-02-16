#pragma once
#include "../QueryBase.h"

class NotQuery : public QueryBase
{
public:
    NotQuery(const std::shared_ptr<const QueryBase> op) : param(op)
    {
#ifdef TEST
        std::cout << "NotQuery(const std::shared_ptr<const QueryBase> op)" << std::endl;
#endif
    }
    QueryResult evaluate() const override;
    std::string parameters() const override;

private:
    const std::shared_ptr<const QueryBase> param;
};