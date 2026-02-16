#include "../../Include/UniQuery/WordQuery.h"

QueryResult WordQuery::evaluate() const
{
#ifdef TEST
    std::cout << "WordQuery::evaluate()" << std::endl;
#endif
    return TextFile->query(parameters());
}

std::string WordQuery::parameters() const
{
#ifdef TEST
    std::cout << "WordQuery::parameters()" << std::endl;
#endif
    return operand;
}