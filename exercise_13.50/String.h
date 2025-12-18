#pragma once
#include <iostream>
#include <memory>
#include <utility>

class String
{
    // Exercise 14.7.
    friend std::ostream &operator<<(std::ostream &, const String &);

public:
    int size() const
    {
        return past_end - first;
    }
    int capacity()
    {
        return cap - first;
    }
    String() : first(nullptr), past_end(nullptr), cap(nullptr) {}
    String(String &&rhs) noexcept : first(rhs.first), past_end(rhs.past_end), cap(rhs.cap)
    {
        std::cout << "Called String::String(String &&rhs)." << std::endl;
        rhs.first = rhs.past_end = rhs.cap = nullptr;
    }

    String(const char *arr);
    String(const String &rhs);

    String &operator=(const String &rhs);
    String &operator=(String &&rhs) noexcept;

    void push_back(const char &c);

    ~String() { free(); }

private:
    std::pair<char *, char *> construct(const char *beg, const char *end);
    void free();
    void reallocate();
    char *first;
    char *past_end;
    char *cap;
    static std::allocator<char> alloc;
};
