#include <iostream>
#include <string>
#include <memory>
int main()
{
    int n = 5;
    std::string s;
    std::allocator<std::string> alloc;
    std::string *p = alloc.allocate(n);
    std::string *q = p;
    while (std::cin >> s && q != p + n)
        alloc.construct(q++, s);
    const size_t size = q - p;
    // Print
    for (auto i = 0; i < 5; i++)
        std::cout << p[i] << " ";
    while (q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, n);
}