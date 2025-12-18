#pragma once
#include <string>

class Employee
{
    static int count;
    int ID;
    std::string name;

public:
    Employee() : ID(++count) {}
    Employee(const std::string &name) : ID(++count), name(name) {}
    // It needs to define a copy constructor and an assignment operator to ensure that all instances of the class hold unique IDs.
    Employee(const Employee &rhs) : ID(++count), name(rhs.name) {}
    Employee &operator=(const Employee &rhs)
    {
        ID = ++count;
        name = rhs.name;
    }
};
