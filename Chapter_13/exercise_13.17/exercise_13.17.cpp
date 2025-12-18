#include <iostream>

struct numbered_synth_cop
{
    static int count;
    int mysn = 0;
};

struct numbered
{
    static int count;
    int mysn;
    numbered() : mysn(count++) {}
    numbered(const numbered &rhs) : mysn(count++) {}
};

int numbered::count = 0;
int numbered_synth_cop::count = 0;

void f(numbered_synth_cop s) { std::cout << s.mysn << std::endl; }

void f(numbered s) { std::cout << s.mysn << std::endl; }

void f_ref(const numbered &s) { std::cout << s.mysn << std::endl; }

int main()
{
    numbered_synth_cop a0, b0 = a0, c0 = b0;
    f(a0);                              // 0
    f(b0);                              // 0
    f(c0);                              // 0
    numbered a, b = a, c = b;           // a: 0; b: 1; c: 2.
    f(a);                               // 3
    f(b);                               // 4
    f(c);                               // 5
    numbered a_r, b_r = a_r, c_r = b_r; // a: 6; b: 7; c: 8.
    f_ref(a_r);                         // 6
    f_ref(b_r);                         // 7
    f_ref(c_r);                         // 8
}