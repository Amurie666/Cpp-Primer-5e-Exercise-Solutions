#include "Quote.h"

Quote::Quote() { std::cout << "Quote()" << std::endl; };
Quote::Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price)
{
}

Quote::Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price)
{
}
Quote &Quote::operator=(const Quote &rhs)
{

    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

Quote *Quote::clone() const &
{
    return new Quote(*this);
}
Quote *Quote::clone() &&
{
    return new Quote(std::move(*this));
}

std::string Quote::isbn() const { return bookNo; }

double Quote::net_price(std::size_t n) const
{
    return n * price;
}

void Quote::debug() const
{
    std::cerr << "REQUESTED ON QUOTE\n";
    std::cerr << "bookNo: " << bookNo << ", price: " << price << std::endl;
}

double print_total(std::ostream &os,
                   const Quote &item, size_t n)
{

    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}