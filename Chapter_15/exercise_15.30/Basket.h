#pragma once
#include "Quote.h"
#include "Discounts.h"
#include <set>
#include <memory>

class Basket
{
public:
    void add_item(const Quote &qt);
    void add_item(Quote &&qt);
    double total_receipt(std::ostream &) const;

private:
    static bool compare(const std::shared_ptr<Quote> lhs, const std::shared_ptr<Quote> rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};