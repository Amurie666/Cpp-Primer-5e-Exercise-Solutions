#include "StrBlobPtr.h"

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string& msg) const {
        auto lck_ptr = ptr.lock();
        if(!lck_ptr)
            throw std::out_of_range("deleted vector");
        if(i >= lck_ptr->size())
            throw std::out_of_range(msg);
        return lck_ptr;
}

std::string& StrBlobPtr::deref() const {
        auto blb_ptr = check(curr, "dereference past end");
        return (*blb_ptr)[curr];
}

StrBlobPtr::StrBlobPtr(StrBlob& blb, size_t i) : ptr(blb.data), curr(i) {}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "off the end increment");
    ++curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>> C_StrBlobPtr::check(size_t i, const std::string& msg) const {
        auto lck_ptr = ptr.lock();
        if(!lck_ptr)
            throw std::out_of_range("deleted vector");
        if(i >= lck_ptr->size())
            throw std::out_of_range(msg);
        return lck_ptr;
}

const std::string& C_StrBlobPtr::deref() const {
        auto blb_ptr = check(curr, "dereference past end");
        return (*blb_ptr)[curr];
}

C_StrBlobPtr::C_StrBlobPtr(const StrBlob& blb, size_t i) : ptr(blb.data), curr(i) {}

C_StrBlobPtr& C_StrBlobPtr::incr() {
    check(curr, "off the end increment");
    ++curr;
    return *this;
}
