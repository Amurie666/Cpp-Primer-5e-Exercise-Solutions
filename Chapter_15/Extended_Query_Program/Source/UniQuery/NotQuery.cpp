#include "../../Include/UniQuery/NotQuery.h"

QueryResult NotQuery::evaluate() const
{
#ifdef TEST
    std::cout << "NotQuery::evaluate()" << std::endl;
#endif
    std::shared_ptr<std::set<size_t>> result = std::make_shared<std::set<size_t>>();
    auto evaled_param = param->evaluate();
    auto param_lines = evaled_param.lines;
    for (size_t i = 0; i < evaled_param.fptr->size(); i++)
        if (param_lines->find(i) == param_lines->end())
            result->insert(i);
    return QueryResult(parameters(), evaled_param.fptr, result);
}

std::string NotQuery::parameters() const
{
#ifdef TEST
    std::cout << "NotQuery::parameters()" << std::endl;
#endif
    return ("~(" + param->parameters() + ")");
}