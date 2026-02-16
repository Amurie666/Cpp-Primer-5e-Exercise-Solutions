#include "Basket.h"

int main()
{
    Basket basket;
    basket.add_item(Bulk_quote("Beyond Horizon", 120, 25, 0.20));
    basket.add_item(Bulk_quote("Stranger Things", 90, 5, 0.15));
    basket.add_item(Bulk_quote("Stranger Things", 80, 15, 0.35));
    double total = 0.0;
    basket.total_receipt(std::cout);
    while (true)
        ;
}