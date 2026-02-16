#include "../../Include/BiQuery/BiQuery.h"

BiQuery::BiQuery(QueryBase *lhs, QueryBase *rhs) : operand1(lhs), operand2(rhs)
{
    ++operand1->ref_count;
    ++operand2->ref_count;
}
BiQuery::BiQuery(const BiQuery &BQ) : operand1(BQ.operand1), operand2(BQ.operand2)
{
    ++operand1->ref_count;
    ++operand2->ref_count;
}
BiQuery &BiQuery::operator=(const BiQuery &BQ)
{
    ++BQ.operand2->ref_count;
    ++BQ.operand1->ref_count;
    free();
    operand1 = BQ.operand1;
    operand2 = BQ.operand2;
    return *this;
}
BiQuery::BiQuery(BiQuery &&BQ) noexcept : operand1(BQ.operand1), operand2(BQ.operand2)
{
    operand1 = operand2 = nullptr;
}
BiQuery &BiQuery::operator=(BiQuery &&BQ) noexcept
{
    if (this != &BQ)
    {
        free();
        operand1 = BQ.operand1;
        operand2 = BQ.operand2;
        operand1 = operand2 = nullptr;
    }
    return *this;
}

void BiQuery::free()
{
    free(operand1);
    free(operand2);
}

void BiQuery::free(QueryBase *op)
{
    if (!--op->ref_count)
        delete op;
}