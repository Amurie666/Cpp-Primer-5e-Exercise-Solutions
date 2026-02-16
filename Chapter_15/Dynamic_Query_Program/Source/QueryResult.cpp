#include "../Include/QueryResult.h"

QueryResult::QueryResult(
    const std::string &word,
    std::shared_ptr<std::vector<std::string>> file,
    std::shared_ptr<std::set<size_t>> lines) : word(word), fptr(file), lines(lines)
{
}

std::ostream &print(std::ostream &out, const QueryResult &qr)
{
    out << "The query for \"" << qr.word << "\" yields " << qr.lines->size() << (qr.lines->size() == 1 ? " result." : " results.") << std::endl;
    for (auto it = qr.lines->begin(); it != qr.lines->end(); it++)
        out << "\t (line " << *it << ") " << (*qr.fptr)[*it - 1] << std::endl;
    return out;
}