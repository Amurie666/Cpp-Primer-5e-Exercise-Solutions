#include <iostream>

int main()
{
    int x = 10;
    std::cout << x << std::endl;
    auto f = [&x]() -> bool
    { return x ? --x : x; };
    f();
    f();
    std::cout << x;
}