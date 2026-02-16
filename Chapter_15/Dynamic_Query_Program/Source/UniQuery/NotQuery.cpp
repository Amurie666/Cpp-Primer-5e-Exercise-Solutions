#include "../../Include/UniQuery/NotQuery.h"

// Copy-Move.

NotQuery::NotQuery(QueryBase *op) : operand(op)
{
    ++operand->ref_count;
}

NotQuery::NotQuery(const NotQuery &op) : operand(op.operand) { ++operand->ref_count; }

NotQuery::NotQuery(NotQuery &&op) noexcept : operand(op.operand) { op.operand = nullptr; }

NotQuery &NotQuery::operator=(const NotQuery &NQ)
{
    ++NQ.operand->ref_count;
    free();
    operand = NQ.operand;
    return *this;
}

NotQuery &NotQuery::operator=(NotQuery &&NQ) noexcept
{
    if (this != &NQ)
    {
        free();
        operand = NQ.operand;
        operand = nullptr;
    }
    return *this;
}

// Other.

QueryResult NotQuery::evaluate() const
{
    std::shared_ptr<std::set<size_t>> result = std::make_shared<std::set<size_t>>();
    auto evaled_param = operand->evaluate();
    auto param_lines = evaled_param.lines;
    for (size_t i = 0; i < evaled_param.fptr->size(); i++)
        if (param_lines->find(i) == param_lines->end())
            result->insert(i);
    return QueryResult(parameters(), evaled_param.fptr, result);
}

std::string NotQuery::parameters() const
{
    return ("~(" + operand->parameters() + ")");
}

void NotQuery::free()
{
    if (!--operand->ref_count)
    {
        delete operand;
    }
}