#include <vector>
#include <algorithm>
#include <iostream>

// Foo.
class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
    // Removed private: for the sake of testing.
    std::vector<int> data;
};
Foo Foo::sorted() &&
{
    std::sort(data.begin(), data.end());
    return *this;
}
Foo Foo::sorted() const &
{
    std::cout << "Foo Foo::sorted() const &" << std::endl;
    Foo ret(*this);
    return ret.sorted();
}
// Foo_1.
class Foo_1
{
public:
    Foo_1 sorted() &&;
    Foo_1 sorted() const &;
    // Removed private: for the sake of testing.
    std::vector<int> data;
};

Foo_1 Foo_1::sorted() &&
{
    std::cout << "Foo_1 Foo_1::sorted() &&" << std::endl;
    std::sort(data.begin(), data.end());
    return *this;
}

Foo_1 Foo_1::sorted() const &
{
    std::cout << "Foo_1 Foo_1::sorted() const &" << std::endl;
    return Foo_1(*this).sorted();
}

int main()
{
    Foo f;
    Foo_1 f1;
    f.data = {4, 2, 1};
    f1.data = {4, 2, 1};
    f1.sorted();
    f.sorted();
}
