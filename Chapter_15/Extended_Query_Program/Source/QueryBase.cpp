#include "../Include/QueryBase.h"

std::unique_ptr<TextQuery> QueryBase::TextFile = nullptr;

void read(const std::string directory)
{
    std::ifstream file(directory);
    if (file)
        QueryBase::TextFile = std::make_unique<TextQuery>(file);
    else
        throw std::runtime_error("Could not open file with the name or location'" + directory + "'");
}