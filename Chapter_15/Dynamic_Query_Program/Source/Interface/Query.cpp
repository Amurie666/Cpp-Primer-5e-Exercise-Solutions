#include "../../Include/Interface/Query.h"

// Friends.

Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs.result, rhs.result);
}
Query operator|(const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs.result, rhs.result);
}
Query operator~(const Query &op)
{
    return new NotQuery(op.result);
}

std::ostream &operator<<(std::ostream &out, const Query &qry)
{
    out << qry.parameters();
    return out;
}

// Members.

QueryResult Query::evaluate() const
{
    return result->evaluate();
}

std::string Query::parameters() const
{
    return result->parameters();
}

Query::Query(const std::string wrd) : result(new WordQuery(wrd))
{
    ++result->ref_count;
}

// Copy-Move.

Query::Query(const Query &rhs) : result(rhs.result) { ++result->ref_count; }
Query::Query(Query &&rhs) noexcept : result(rhs.result) { rhs.result = nullptr; }
Query &Query::operator=(const Query &rhs)
{
    ++rhs.result->ref_count;
    free();
    result = rhs.result;
    return *this;
}
Query &Query::operator=(Query &&rhs) noexcept
{
    if (this != &rhs)
    {
        result = rhs.result;
        rhs.result = nullptr;
    }
    return *this;
}

void Query::free()
{
    if (!--result->ref_count)
        delete result;
}
Query::Query(QueryBase *op) : result(op)
{
    ++result->ref_count;
}
