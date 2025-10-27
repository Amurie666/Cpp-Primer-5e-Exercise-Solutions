#include <iostream>
#include <string>

void find_char_v1(const std::string &s, const std::string &srch)
{
    size_t pos = s.find_first_of(srch, 0);
    while (pos != std::string::npos)
    {
        std::cout << "Character " << s[pos] << " at " << pos << std::endl;
        pos = s.find_first_of(srch, pos + 1);
    }
}

void find_char_v2(const std::string &s, const std::string &srch)
{
    size_t pos = s.find_first_not_of(srch, 0);
    size_t i = 0;
    while (pos != std::string::npos)
    {
        for (; i < pos; i++)
            std::cout << "Character " << s[i] << " at " << i << std::endl;
        i = pos + 1;
        if ((pos = s.find_first_not_of(srch, i)) == std::string::npos)
            pos = s.size();
    }
}

int main()
{
    std::string s = "ab2c3d7R4E6";
    std::cout << "Numbers location (version 1):" << std::endl;
    find_char_v1(s, "0123456789");
    std::cout << "Alphabetic characters location (version 1):" << std::endl;
    find_char_v1(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::cout << "Numbers location (version 2):" << std::endl;
    find_char_v1(s, "0123456789");
    std::cout << "Alphabetic characters location (version 2):" << std::endl;
    find_char_v1(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    return 0;
}