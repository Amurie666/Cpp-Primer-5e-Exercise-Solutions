#pragma once
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
#include "StrBlob.h"
// Exercise 12.19
class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &blb, size_t i = 0);
    std::string &deref() const;
    StrBlobPtr &incr();

private:
    std::weak_ptr<std::vector<std::string>> ptr;
    size_t curr;
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string &msg) const;
};
// Exercise_12.22
/*
 * Changes made:
 * Allowed C_StrBlobPtr to be bound to a const StrBlob object by modifying a constructor parameter.
 * Modified the deref() function to allow the return of a const string& reference instead of a non-const string& one.
 * Without this amendment, C_StrBlobPtr would be allowed to modify a const StrBlob object, which is logically incoherent.
 */
class C_StrBlobPtr
{
public:
    C_StrBlobPtr() : curr(0) {}
    C_StrBlobPtr(const StrBlob &blb, size_t i = 0);
    const std::string &deref() const;
    C_StrBlobPtr &incr();

private:
    std::weak_ptr<std::vector<std::string>> ptr;
    size_t curr;
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string &msg) const;
};
