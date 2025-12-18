#pragma once
#include <string>
class P_HasPtr
{
public:
    P_HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    P_HasPtr(const P_HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }
    P_HasPtr &operator=(const P_HasPtr &rhs)
    {
        // use is always initialized to 1 so incrementing it will make it 2.
        ++*rhs.use;
        if (--*use == 0)
        { // For self-assignment, this is never 0.
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        use = rhs.use;
        i = rhs.i;
        return *this;
    }
    ~P_HasPtr()
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

private:
    std::string *ps;
    std::size_t *use;
    int i;
};
