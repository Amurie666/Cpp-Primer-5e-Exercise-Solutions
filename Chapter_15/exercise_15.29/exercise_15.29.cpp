#include <memory>
#include <vector>
#include "Quote.h"
#include "Discounts.h"

int main()
{
    // Discrepancy exists because in Exercise 15.28 Bulk_quote objects are converted to Quote objects.
    // In contrast, this version dynamically binds Bulk_quote objects to Quote pointers.
    std::vector<std::shared_ptr<Quote>> basket;
    basket.push_back(std::make_shared<Bulk_quote>("Beyond Horizon", 120, 25, 0.20));
    basket.push_back(std::make_shared<Bulk_quote>("Stranger Things", 90, 5, 0.15));
    basket.push_back(std::make_shared<Bulk_quote>("Stranger Things", 80, 15, 0.35));
    double total = 0.0;
    print_total(std::cout, *basket[0], 60);
    print_total(std::cout, *basket[1], 20);
    print_total(std::cout, *basket[2], 10);
    while (true)
        ;
}