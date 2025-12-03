#ifndef STRBLOBPTR_h
#define STRBLOBPTR_h
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
#include "StrBlob.h"
class StrBlobPtr {
    public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& blb, size_t i = 0);
    std::string& deref() const;
    StrBlobPtr& incr();
    private:
    std::weak_ptr<std::vector<std::string>> ptr;
    size_t curr;
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string& msg) const;

};

class C_StrBlobPtr {
    public:
    C_StrBlobPtr() : curr(0) {}
    C_StrBlobPtr(const StrBlob& blb, size_t i = 0);
    const std::string& deref() const;
    C_StrBlobPtr& incr();
    private:
    std::weak_ptr<std::vector<std::string>> ptr;
    size_t curr;
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string& msg) const;
};
#endif