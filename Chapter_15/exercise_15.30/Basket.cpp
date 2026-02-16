#include "Basket.h"

void Basket::add_item(const Quote &qt)
{
    items.insert(std::shared_ptr<Quote>(qt.clone()));
}

void Basket::add_item(Quote &&qt)
{
    items.insert(std::shared_ptr<Quote>(std::move(qt).clone()));
}

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin();
         iter != items.cend();
         iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}