#include <memory>
#include <vector>
#include <string>
#ifndef STRBLOB_H
#define STRBLOB_H
class StrBlobPtr;
class C_StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    friend class C_StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const;
    bool empty() const;
    // addandremove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    // element access
    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;
    StrBlobPtr beg();
    StrBlobPtr end();
    C_StrBlobPtr beg() const;
    C_StrBlobPtr end() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;

};
#endif