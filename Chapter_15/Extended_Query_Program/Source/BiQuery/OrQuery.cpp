#include "../../Include/BiQuery/OrQuery.h"

QueryResult OrQuery::evaluate() const
{
#ifdef TEST
    std::cout << "OrQuery::evaluate()" << std::endl;
#endif
    auto leftQuery = operand1->evaluate();
    auto rightQuery = operand2->evaluate();
    auto leftResult = *leftQuery.lines;
    auto rightResult = *rightQuery.lines;
    auto result = std::make_shared<std::set<size_t>>();
    std::set_union(leftResult.begin(), leftResult.end(),
                   rightResult.begin(), rightResult.end(),
                   std::inserter(*result, result->begin()));
    return QueryResult(parameters(), leftQuery.fptr, result);
}

std::string OrQuery::parameters() const
{
#ifdef TEST
    std::cout << "OrQuery::parameters()" << std::endl;
#endif
    return '(' + operand1->parameters() + " | " + operand2->parameters() + ')';
}