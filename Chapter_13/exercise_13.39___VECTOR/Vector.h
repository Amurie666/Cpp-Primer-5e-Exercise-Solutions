#pragma once
// #include <algorithm>
#include <memory>
#include <exception>
#include <initializer_list>
// Templates are introduced later.
template <typename T>
class Vector
{
private:
    static std::allocator<T> alloc;
    T *elements;
    T *first_free;
    T *cap;
    std::pair<T *, T *> alloc_n_copy(const T *beg, const T *end)
    {
        T *first = alloc.allocate(end - beg);
        T *last = std::uninitialized_copy(beg, end, first);
        return {first, last};
    }
    void free()
    {
        // Exercise 13.43
        /*
         * for_each(elements, first_free, [] (const T& elem) { alloc.destroy(&elem);})
         * I prefer the original version because elements are destroyed in reverse order of construction.
         * Although we could use reverse iterators, that still would require two extra function calls,
         * which makes the code a bit harder to read.
         */
        if (elements)
        {
            for (auto it = first_free; it != elements; alloc.destroy(--it))
                ;
            alloc.deallocate(elements, capacity());
        }
    }
    void reallocate(size_t new_cap)
    {
        if (new_cap <= capacity())
            return;
        auto new_elem = alloc.allocate(new_cap);
        auto dest = new_elem;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = new_elem;
        first_free = dest;
        cap = elements + new_cap;
    }
    void reallocate() { reallocate(size() ? 2 * size() : 1); }
    void save_space()
    {
        if (size() == capacity())
            reallocate();
    }

public:
    Vector() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vector(const Vector &rhs)
    {
        auto &data = alloc_n_copy(rhs.begin(), rhs.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    Vector(Vector &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
    {
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    // Exercise_13.40
    Vector(const std::initializer_list<T> rhs)
    {
        auto &data = alloc_n_copy(rhs.begin(), rhs.end());
        elements = data.first;
        first_free = cap = data.second;
    }

    Vector &operator=(const Vector &rhs)
    {
        auto &data = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }
    Vector &operator=(Vector &&rhs) noexcept
    {
        if (this != &rhs)
        {
            free();
            elements = rhs.elements;
            first_free = rhs.first_free;
            cap = rhs.cap;
            rhs.elements = rhs.first_free = rhs.cap = nullptr;
        }
        return *this;
    }
    ~Vector()
    {
        free();
    }
    void push_back(const T &data)
    {
        // Exercise 13.41
        /* We used postfix increment here so that we could:
           1) Construct the memory pointed to by first_free.
           2) Then increment first_free, making it point to the memory off the end.
          If we used prefix increment instead:
           1) first_free will be incremented first, and constructed afterwards.
           2) Behaviour will likely be undefined in this case, and an unconstructed gap between elements will exist.
       */
        save_space();
        alloc.construct(first_free++, data);
    }
    void push_back(T &&data)
    {
        save_space();
        alloc.construct(first_free++, std::move(data));
    }
    void pop_back()
    {
        if (size() != 0)
            alloc.destroy(--first_free);
    }
    T &operator[](size_t i)
    {
        if (i >= size())
            std::__throw_out_of_range("out of range");
        return *(elements + i);
    }
    const T &operator[](size_t i) const
    {
        if (i >= size())
            std::__throw_out_of_range("out of range");
        return *(elements + i);
    }

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    void reserve(size_t n) { reallocate(n); }

    void resize(size_t n, T t = T())
    {
        if (n < size())
            for (auto i = size() - n; i != 0; --i)
                pop_back();
        if (n > size())
            for (auto i = 0; i != n - size(); i++)
                push_back(t);
    }

    const T *cbegin() const { return elements; }
    const T *cend() const { return first_free; }

    const T *cbegin() { return elements; }
    const T *cend() { return first_free; }

    T *begin() { return elements; }
    T *end() { return first_free; }
};

template <typename T>
std::allocator<T> Vector<T>::alloc = std::allocator<T>();