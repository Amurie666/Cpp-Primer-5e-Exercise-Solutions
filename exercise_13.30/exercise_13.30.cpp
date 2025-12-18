#include <string>
#include <iostream>

class HasPtr
{
public:
    friend std::ostream &operator<<(std::ostream &, const HasPtr &);
    friend void swap(HasPtr &, HasPtr &);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    HasPtr &operator=(const HasPtr &rhs)
    {
        std::string temp = *rhs.ps;
        delete ps;
        ps = new std::string(temp);
        i = rhs.i;
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    std::cout << "Swap(lhs, rhs);" << std::endl;
    swap(lhs.ps, rhs.ps);
    std::swap(lhs.i, rhs.i);
}

std::ostream &operator<<(std::ostream &out, const HasPtr &hp)
{
    out << "value: " << *hp.ps << "; index: " << hp.i << "; loc: " << hp.ps;
    return out;
}

int main()
{
    HasPtr hp1("Hello");
    HasPtr hp2("Hey");
    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;
    swap(hp1, hp2);
    std::cout << "hp1: " << hp1 << std::endl;
    std::cout << "hp2: " << hp2 << std::endl;
}