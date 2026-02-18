#include "StrBlobPtr.h"
#include "../STRBLOB/StrBlob.h"

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string &msg) const
{
    auto lck_ptr = ptr.lock();
    if (!lck_ptr)
        throw std::out_of_range("deleted vector");
    if (i >= lck_ptr->size())
        throw std::out_of_range(msg);
    return lck_ptr;
}

std::string &StrBlobPtr::deref() const
{
    auto blb_ptr = check(curr, "dereference past end");
    return (*blb_ptr)[curr];
}

std::string &StrBlobPtr::operator[](size_t i) const
{
    auto blb_ptr = check(i, "dereference past end");
    return (*blb_ptr)[i];
}

StrBlobPtr::StrBlobPtr(StrBlob &blb, size_t i) : ptr(blb.data), curr(i) {}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "off the end increment");
    ++curr;
    return *this;
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return (*(lhs.ptr.lock()) == *(rhs.ptr.lock())) && !(lhs < rhs) && !(rhs < lhs);
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs > rhs || lhs == rhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator<(const C_StrBlobPtr &lhs, const C_StrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}

bool operator>(const C_StrBlobPtr &lhs, const C_StrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator>=(const C_StrBlobPtr &lhs, const C_StrBlobPtr &rhs)
{
    return lhs > rhs || lhs == rhs;
}

bool operator<=(const C_StrBlobPtr &lhs, const C_StrBlobPtr &rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator==(const C_StrBlobPtr &lhs, const C_StrBlobPtr &rhs)
{
    return (*(lhs.ptr.lock()) == *(rhs.ptr.lock())) && !(lhs < rhs) && !(rhs < lhs);
}

bool operator!=(const C_StrBlobPtr &lhs, const C_StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}
/*
std::string &C_StrBlobPtr::operator[](size_t i)
{
    auto blb_ptr = check(i, "dereference past end");
    return (*blb_ptr)[i];
} */

const std::string &C_StrBlobPtr::operator[](size_t i) const
{
    auto blb_ptr = check(i, "dereference past end");
    return (*blb_ptr)[i];
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment off the end");
    ++curr;
    return *this;
}
StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "increment past begin");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator++(int)
{
    StrBlobPtr temp = *this;
    ++*this;
    return temp;
}

StrBlobPtr &StrBlobPtr::operator--(int)
{
    StrBlobPtr temp = *this;
    --*this;
    return temp;
}

std::string &StrBlobPtr::operator*() const
{
    auto blb_ptr = check(curr, "dereference past end");
    return (*blb_ptr)[curr];
}

std::string *StrBlobPtr::operator->() const
{
    return &operator*();
}

const std::string &C_StrBlobPtr::operator*() const
{
    auto blb_ptr = check(curr, "dereference past end");
    return (*blb_ptr)[curr];
}

const std::string *C_StrBlobPtr::operator->() const
{
    return &operator*();
}

StrBlobPtr StrBlobPtr::operator+(size_t i)
{
    StrBlobPtr temp(*this);
    temp.curr += i;
    return temp;
}
StrBlobPtr StrBlobPtr::operator-(size_t i)
{
    StrBlobPtr temp(*this);
    temp.curr -= i;
    return temp;
}

StrBlobPtr StrBlobPtr::operator+(size_t i) const
{
    StrBlobPtr temp(*this);
    temp.curr += i;
    return temp;
}
StrBlobPtr StrBlobPtr::operator-(size_t i) const
{
    StrBlobPtr temp(*this);
    temp.curr -= i;
    return temp;
}

std::shared_ptr<const std::vector<std::string>> C_StrBlobPtr::check(size_t i, const std::string &msg) const
{
    auto lck_ptr = ptr.lock();
    if (!lck_ptr)
        throw std::out_of_range("deleted vector");
    if (i >= lck_ptr->size())
        throw std::out_of_range(msg);
    return lck_ptr;
}

const std::string &C_StrBlobPtr::deref() const
{
    auto blb_ptr = check(curr, "dereference past end");
    return (*blb_ptr)[curr];
}

C_StrBlobPtr::C_StrBlobPtr(const StrBlob &blb, size_t i) : ptr(blb.data), curr(i) {}

C_StrBlobPtr &C_StrBlobPtr::incr()
{
    check(curr, "off the end increment");
    ++curr;
    return *this;
}
