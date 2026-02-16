#pragma once
#include <string>
#include <iostream>

class Quote
{
public:
    Quote();
    Quote(const std::string &, double);
    Quote(const Quote &);
    Quote &operator=(const Quote &);

    virtual Quote *clone() const &;
    virtual Quote *clone() &&;
    std::string isbn() const;
    virtual double net_price(std::size_t) const;
    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
    virtual void debug() const;
};

double print_total(std::ostream &, const Quote &, size_t);