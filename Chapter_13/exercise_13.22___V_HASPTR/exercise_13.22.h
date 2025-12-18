#pragma once
#include <string>
class V_HasPtr
{
public:
    V_HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    V_HasPtr(const V_HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    V_HasPtr &operator=(const V_HasPtr &rhs)
    {
        std::string temp = *rhs.ps;
        delete ps;
        ps = new std::string(temp);
        i = rhs.i;
        return *this;
    }
    ~V_HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};
