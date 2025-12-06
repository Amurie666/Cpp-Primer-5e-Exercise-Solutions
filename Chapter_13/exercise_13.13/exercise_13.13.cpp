#include <iostream>
#include <vector>

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X &) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X &rhs)
    {
        std::cout << "X& operator=(const X& rhs)" << std::endl;
        return *this;
    }
    ~X()
    {
        std::cout << "~X()" << std::endl;
    }
};
X use_X(X x)
{
    return x;
}
void manipulate_X(const X &x)
{
    std::cout << "manipulate_X() called but does nothing\n";
}
int main()
{
    X x;
    std::cout << "Constructed.\n";
    std::cout << "\t As nonreference parameters.\n";
    // as nonreference parameters.
    std::cout << "use_X()\n";
    std::cout << "Copy constructor called two times, and third time may be omitted here.\n";
    X z = use_X(x);
    std::cout << "Destructor is expected to have been called already.\n";
    // as reference parameters.
    std::cout << "\t As reference parameters.\n";
    std::cout << "manipulate_X()\n";
    manipulate_X(x);
    std::cout << "No copy-control members are expected to be called here.\n";
    std::cout << "\t Dynamically allocated.\n";
    std::cout << "Default constructor is expected to be called here.\n";
    X *xptr = new X;
    std::cout << "\t In container.\n";
    std::cout << "Copy constructor is expected to be called six times here: make three temporary copies and copy them again into a container.\n";
    std::vector<X> vec = {x, z, *xptr};
    std::cout << "Destructor is expected to have already been called three times here: destroy the three temporary objects.\n";
    std::cout << "\t Assignment.\n";
    std::cout << "Assignment is expected to be called 1 time here.\n";
    *xptr = x;
    std::cout << "\t Deletion of dynamically allocated object.\n";
    std::cout << "Destructor called one time.\n";
    delete xptr;
    std::cout << "Destructor called five times.\n";
}