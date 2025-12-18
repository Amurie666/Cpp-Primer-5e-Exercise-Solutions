#include <iostream>
#include "String.h"

void test_constructor()
{
    std::cout << "Test Constructor:\n";
    String s1("Hello");
    std::cout << "s1: " << s1 << "\n";
    std::cout << "Size: " << s1.size() << ", Capacity: " << s1.capacity() << "\n\n";
}

void test_copy_constructor()
{
    std::cout << "Test Copy Constructor:\n";
    String s1("CopyMe");
    String s2(s1);
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n";
    std::cout << "Size: " << s2.size() << ", Capacity: " << s2.capacity() << "\n\n";
}

void test_move_constructor()
{
    std::cout << "Test Move Constructor:\n";
    String s1("MoveMe");
    String s2(std::move(s1));
    std::cout << "s2 (after move): " << s2 << "\n";
    std::cout << "Size: " << s2.size() << ", Capacity: " << s2.capacity() << "\n";
    std::cout << "s1 (should be empty): " << s1 << "\n\n";
}

void test_copy_assignment()
{
    std::cout << "Test Copy Assignment:\n";
    String s1("AssignMe");
    String s2;
    s2 = s1;
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n\n";
}

void test_move_assignment()
{
    std::cout << "Test Move Assignment:\n";
    String s1("MoveAssign");
    String s2;
    s2 = std::move(s1);
    std::cout << "s2: " << s2 << "\n";
    std::cout << "s1 (should be empty): " << s1 << "\n\n";
}

void test_push_back()
{
    std::cout << "Test push_back:\n";
    String s;
    s.push_back('H');
    s.push_back('i');
    s.push_back('!');
    std::cout << "s: " << s << "\n";
    std::cout << "Size: " << s.size() << ", Capacity: " << s.capacity() << "\n\n";
}

int main()
{
    char q;

    while (true)
    {
        std::cout << "Running String tests... " << std::endl;

        test_constructor();
        test_copy_constructor();
        test_move_constructor();
        test_copy_assignment();
        test_move_assignment();
        test_push_back();

        std::cout << std::endl
                  << "Enter 't' to terminate, anything else to run again: ";
        std::cin >> q;
        if (q == 't' || q == 'T')
            break;
    }
    std::cout << "Exiting test..." << std::endl;
    return 0;
}
