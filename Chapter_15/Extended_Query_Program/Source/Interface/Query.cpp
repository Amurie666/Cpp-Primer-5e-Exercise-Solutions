#include "../../Include/Interface/Query.h"

QueryResult Query::evaluate() const
{
#ifdef TEST
    std::cout << "Query::evaluate()" << std::endl;
#endif
    return result->evaluate();
}

std::string Query::parameters() const
{
#ifdef TEST
    std::cout << "Query::parameters()" << std::endl;
#endif
    return result->parameters();
}

std::ostream &operator<<(std::ostream &out, const Query &qry)
{
    out << qry.parameters();
    return out;
}

Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<const QueryBase>(new AndQuery(lhs.result, rhs.result));
}
Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<const QueryBase>(new OrQuery(lhs.result, rhs.result));
}
Query operator~(const Query &op)
{
    return std::shared_ptr<const QueryBase>(new NotQuery(op.result));
}