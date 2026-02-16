#pragma once
#include "../QueryBase.h"
#include "../TextQuery.h"

class BiQuery : public QueryBase
{
public:
    BiQuery(std::shared_ptr<const QueryBase> lhs, std::shared_ptr<const QueryBase> rhs) : operand1(lhs), operand2(rhs)
    {
#ifdef TEST
        std::cout << "BiQuery(std::shared_ptr<const QueryBase> lhs, std::shared_ptr<const QueryBase> rhs)" << std::endl;
#endif
    }
    virtual QueryResult evaluate() const = 0;
    virtual std::string parameters() const = 0;
    virtual ~BiQuery() {}

protected:
    const std::shared_ptr<const QueryBase> operand1;
    const std::shared_ptr<const QueryBase> operand2;
};