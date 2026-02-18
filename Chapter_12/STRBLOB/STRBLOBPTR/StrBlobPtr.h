#pragma once
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
class StrBlob;
// Exercise 12.19
class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    StrBlobPtr &operator++(int);
    StrBlobPtr &operator--(int);
    StrBlobPtr operator+(size_t);
    StrBlobPtr operator-(size_t);
    StrBlobPtr operator+(size_t) const;
    StrBlobPtr operator-(size_t) const;
    std::string &operator[](size_t) const;
    std::string *operator->() const;
    std::string &operator*() const;
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &blb, size_t i = 0);
    std::string &deref() const;
    StrBlobPtr &incr();

private:
    std::weak_ptr<std::vector<std::string>> ptr;
    size_t curr;
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string &msg) const;
};

class C_StrBlobPtr
{
    friend bool operator==(const C_StrBlobPtr &, const C_StrBlobPtr &);
    friend bool operator!=(const C_StrBlobPtr &, const C_StrBlobPtr &);
    friend bool operator<(const C_StrBlobPtr &, const C_StrBlobPtr &);
    friend bool operator>(const C_StrBlobPtr &, const C_StrBlobPtr &);

public:
    const std::string *operator->() const;
    const std::string &operator*() const;
    //  std::string &operator[](size_t);
    const std::string &operator[](size_t) const; // C_StrBlobPtr allow the modification of underlying data it points to.
    C_StrBlobPtr() : curr(0) {}
    C_StrBlobPtr(const StrBlob &blb, size_t i = 0);
    const std::string &deref() const;
    C_StrBlobPtr &incr();

private:
    std::weak_ptr<const std::vector<std::string>> ptr;
    size_t curr;
    std::shared_ptr<const std::vector<std::string>> check(size_t i, const std::string &msg) const;
};
