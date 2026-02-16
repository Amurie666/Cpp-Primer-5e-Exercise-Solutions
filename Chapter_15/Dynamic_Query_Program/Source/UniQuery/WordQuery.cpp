#include "../../Include/UniQuery/WordQuery.h"

QueryResult WordQuery::evaluate() const
{
    return TextFile->query(parameters());
}

std::string WordQuery::parameters() const
{
    return operand;
}