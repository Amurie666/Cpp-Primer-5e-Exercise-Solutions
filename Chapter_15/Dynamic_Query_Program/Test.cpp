#include "Include/Interface/Query.h"

int main()
{
    read("SampleText.txt");
    Query query = Query("Roman") & Query("the") | Query("Byron");
    auto result = query.evaluate();
    print(std::cout, result);
    while (true)
        ;
}