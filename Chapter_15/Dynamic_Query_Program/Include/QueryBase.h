#pragma once
#include "TextQuery.h"
#include "QueryResult.h"
#include <memory>

// There might - or might not - be a little inconsistency in the naming convention; I'm just THAT lazy to recheck，本当にごめんなさい。
// QueryBase can rely on synthesized copy-control members.

class QueryBase
{
    friend class Query;
    friend class NotQuery;
    friend class BiQuery;
    friend void read(const std::string directory);

public:
    virtual QueryResult evaluate() const = 0;
    virtual std::string parameters() const = 0;

    virtual ~QueryBase()
    {
    }

protected:
    static const TextQuery *TextFile;
    size_t ref_count = 0; // This counter counts how many objects point to THIS object.
    // Hence, no need for it to be dynamically allocated. The object itself (*this/this), however, is expected to be dynamically allocated either by user code or some sort of a protective interfrace.
};
class Query;
void read(const std::string directory);
