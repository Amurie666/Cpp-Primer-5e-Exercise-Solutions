#include "Discounts.h"

// Bulk_quote

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}


double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

void Bulk_quote::debug() const
{
    std::cerr << "REQUESTED ON BULK_QUOTE\n";
    std::cerr << "Quote Sub-Object:\n";
    Quote::debug();
    std::cerr << "---\n";
    std::cerr << "min_qty: " << qty << ", discount: " << discount << std::endl;
}

// Max_quote

Max_quote::Max_quote(std::string b, double p, std::size_t q, double d) : Disc_quote(b, p, q, d) {}
double Max_quote::net_price(std::size_t n) const
{
    return n > qty ? Quote::net_price(n) : n * ((1 - discount) * price);
}
void Max_quote::debug() const
{
    std::cerr << "REQUESTED ON MAX_QUOTE\n";
    std::cerr << "Quote Sub-Object:\n";
    Quote::debug();
    std::cerr << "---\n";
    std::cerr << "max_qty: " << qty << ", discount: " << discount << std::endl;
}