#include "String.h"
#include <cstring>
#include <iostream>

std::allocator<char> String::alloc = std::allocator<char>();

String::String(const char *arr)
{
    first = alloc.allocate(strlen(arr));
    cap = past_end = first + strlen(arr);
    for (size_t i{0}; i < strlen(arr); i++)
        alloc.construct(first + i, *(arr + i));
}

String::String(const String &rhs)
{
    std::cout << "String::String(const String &rhs) called." << std::endl;
    auto data = construct(rhs.first, rhs.past_end);
    first = data.first;
    past_end = cap = data.second;
}

String &String::operator=(const String &rhs)
{
    std::cout << "String &String::operator=(const String &rhs) called." << std::endl;
    auto data = construct(rhs.first, rhs.past_end);
    free();
    first = data.first;
    past_end = cap = data.second;
    return *this;
}

String &String::operator=(String &&rhs) // noexcept
{
    if (this != &rhs)
    {
        free();
        first = rhs.first;
        past_end = rhs.past_end;
        cap = rhs.cap;
        rhs.first = rhs.past_end = rhs.cap = nullptr;
    }
    return *this;
}

void String::push_back(const char &c)
{
    if (size() == capacity())
        reallocate();
    alloc.construct(past_end++, c);
}

std::pair<char *, char *> String::construct(const char *beg, const char *end)
{
    auto new_first = alloc.allocate(end - beg);
    auto new_past_end = std::uninitialized_copy(beg, end, new_first);
    return std::make_pair(new_first, new_past_end);
}

void String::free()
{
    if (first)
    {
        for (auto it = past_end; it != first; alloc.destroy(--it))
            ;
        alloc.deallocate(first, capacity());
        cap = past_end = first = nullptr;
    }
}

void String::reallocate()
{
    auto new_cap = size() ? 2 * size() : 1;
    auto new_first = alloc.allocate(new_cap);
    past_end = std::uninitialized_copy(std::move_iterator(first), std::move_iterator(past_end), new_first);
    cap = new_first + new_cap;
    first = new_first;
}
// Exercise 14.7.
std::ostream &operator<<(std::ostream &out, const String &s)
{
    for (auto it = s.first; it != s.past_end; out << *it++)
        ;
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.free();
    char c;
    while(c == ' ') { 
        std::cout << "while(c == ' ')" << std::endl;
        in >> c; 
    }
    while(c != ' ') {
        std::cout << "while(c != ' ')" << std::endl;
        s.push_back(c);
        in >> c;
    }
    return in;
}