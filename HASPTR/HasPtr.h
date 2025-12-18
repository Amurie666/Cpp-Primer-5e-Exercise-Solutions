#include <string>
#include <iostream>
#include <cstring>

class HasPtr
{
public:
    friend std::ostream &operator<<(std::ostream &, const HasPtr &);
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr &, const HasPtr &);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    HasPtr(HasPtr &&rhs) noexcept : ps(rhs.ps), i(std::move(rhs.i)) { rhs.ps = nullptr; }
    // For conversion

    HasPtr &operator=(const HasPtr &rhs)
    {
        if (this != &rhs)
        {
            delete ps;
            ps = new std::string(*rhs.ps);
            int i = i;
        }
        return *this;
    }

    HasPtr(const char *arr) : HasPtr(std::string(arr)) {}
    HasPtr &operator=(HasPtr &&rhs) noexcept
    {
        if (this != &rhs)
        {
            delete ps;
            ps = rhs.ps;
            int i = std::move(i);
            rhs.ps = nullptr;
        }
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

std::ostream &operator<<(std::ostream &out, const HasPtr &hp)
{
    out << "value: " << *hp.ps << "; index: " << hp.i << "; loc: " << hp.ps;
    return out;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    swap(lhs.ps, rhs.ps);
    std::swap(lhs.i, rhs.i);
}

inline bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}
