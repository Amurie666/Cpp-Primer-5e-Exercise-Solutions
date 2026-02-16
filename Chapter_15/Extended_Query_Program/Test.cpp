#include "Include/Interface/Query.h"

int main()
{
    std::cout << "RUNNING TEST 1..." << std::endl;
    read("SampleText.txt");
    Query query = Query("Roman") & Query("the") | Query("Byron");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "RUNNING TEST 2..." << std::endl;
    std::cout << query;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "RUNNING TEST 3..." << std::endl;
    auto result = query.evaluate();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "PROGRAM RESULT..." << std::endl;
    print(std::cout, result);
    while (true)
        ;
}