#include <iostream>
#include <string>

int main()
{
    // For some reason, I wanted to do this the ugly way. That is, using raw pointers instead of [].
    const char *s1 = "Hi";
    const char *s2 = " there!";
    // Compute sizes.
    int sz1 = 0;
    const char *tmp1 = s1;
    while (*(tmp1++))
        ++sz1;
    int sz2 = 0;
    const char *tmp2 = s2;
    while (*(tmp2++))
        ++sz2;
    int size = sz1 + sz2;
    // Dynamic array.
    char *arr = new char[size];
    for (int i{0}; i < sz1; i++)
        *(arr + i) = *(s1 + i);
    for (int i{0}; i < sz2; i++)
        *(arr + sz1 + i) = *(s2 + i);
    for (int i{0}; i < size; i++)
        std::cout << *(arr + i);
    std::cout << std::endl;
    delete[] arr;

    std::string Str1 = s1;
    std::string Str2 = s2;
    Str1.append(Str2);
    std::cout << Str1;
}