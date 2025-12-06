#pragma once
#include <memory>
#include <vector>
#include <string>

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    friend class C_StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    // Copy
    StrBlob::StrBlob(const StrBlob &rhs) : data(new std::vector<std::string>(*rhs.data)) {}
    // Assignment
    StrBlob &StrBlob::operator=(const StrBlob &rhs)
    {
        // Move resources to a temporary object. Release ownership and make the shared_ptr point to the temp object.
        data.reset(new std::vector<std::string>(*rhs.data));
        return *this;
    }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // addandremove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    // element access
    std::string &front();
    std::string &back();
    const std::string &StrBlob::front() const;
    const std::string &StrBlob::back() const;
    StrBlobPtr StrBlob::beg();
    StrBlobPtr StrBlob::end();
    C_StrBlobPtr StrBlob::beg() const;
    C_StrBlobPtr StrBlob::end() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
