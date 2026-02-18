#include "StrBlob.h"
#include "../STRBLOBPTR/StrBlobPtr.h"
#include <stdexcept>
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

StrBlob::size_type StrBlob::size() const
{
    return data->size();
}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string &StrBlob::operator[](size_t i)
{
    return (*data)[i];
}

const std::string &StrBlob::operator[](size_t i) const
{
    return (*data)[i];
}

std::string &StrBlob::front()
{
    // if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}
std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
const std::string &StrBlob::front() const
{
    // if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}
const std::string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::beg()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return rhs < lhs;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs < rhs) && !(lhs > rhs);
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs > rhs || lhs == rhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs < rhs || lhs == rhs;
}

C_StrBlobPtr StrBlob::beg() const
{
    return C_StrBlobPtr(*this);
}
C_StrBlobPtr StrBlob::end() const
{
    return C_StrBlobPtr(*this, data->size());
}