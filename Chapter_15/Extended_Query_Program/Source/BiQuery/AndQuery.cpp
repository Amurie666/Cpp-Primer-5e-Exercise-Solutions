#include "../../Include/BiQuery/AndQuery.h"

QueryResult AndQuery::evaluate() const
{
#ifdef TEST
    std::cout << "AndQuery::evaluate()" << std::endl;
#endif
    auto leftQuery = operand1->evaluate();
    auto rightQuery = operand2->evaluate();
    auto leftResult = *leftQuery.lines;
    auto rightResult = *rightQuery.lines;
    auto result = std::make_shared<std::set<size_t>>();
    std::set_intersection(leftResult.begin(), leftResult.end(),
                          rightResult.begin(), rightResult.end(),
                          std::inserter(*result, result->begin()));
    return QueryResult(parameters(), leftQuery.fptr, result);
}

std::string AndQuery::parameters() const
{
#ifdef TEST
    std::cout << "AndQuery::parameters()" << std::endl;
#endif
    return '(' + operand1->parameters() + " & " + operand2->parameters() + ')';
}