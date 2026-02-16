#include "../Include/QueryBase.h"

const TextQuery *QueryBase::TextFile = nullptr;

void read(const std::string directory)
{
    std::ifstream file(directory);
    if (file)
        QueryBase::TextFile = new TextQuery(file);
    else
        throw std::runtime_error("Could not open file with the name or location: '" + directory + "'");
}