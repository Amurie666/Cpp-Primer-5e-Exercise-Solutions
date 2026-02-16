#include "Discounts.h"

int main()
{
    Bulk_quote bq("SomeBook1", 25, 50, 0.25);
    Quote q("SomeBook2", 25);
    print_total(std::cout, q, 49);
    print_total(std::cout, bq, 49);
    print_total(std::cout, q, 50);
    print_total(std::cout, bq, 50); // Should be a different result than the previous line.
    while (true)
        ;
}