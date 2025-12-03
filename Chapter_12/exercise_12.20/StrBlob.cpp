#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <stdexcept>
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

StrBlob::size_type StrBlob::size() const
{
    return data->size();
}
bool StrBlob::empty() const { return data->empty(); }

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}
std::string &StrBlob::front()
{
    // ifthe vectoris empty, check will throw
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
StrBlobPtr StrBlob::beg() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

C_StrBlobPtr StrBlob::beg() const {
    return C_StrBlobPtr(*this);
}
C_StrBlobPtr StrBlob::end() const {
    return C_StrBlobPtr(*this, data->size());
}