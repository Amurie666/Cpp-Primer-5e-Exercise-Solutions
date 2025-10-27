#include <iostream>
#include <vector>


int main()
{
    // Exercise 9.33
    //  Undefined Behaviour because begin will be invalidated after calling insert().
       std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
       auto begin = v.begin();
       while (begin != v.end())
       {
           // do some processing
           ++begin;             // advance begin because we want to insert after this element
           v.insert(begin, 42); // insert the new value
           ++begin;             // advance begin past the element we just added
           std::cout << "TEST" << std::endl;
       }
    
}
