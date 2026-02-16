#pragma once 
#include "Quote.h"

// Check this later.

/*class Bulk_quote : public Quote
{
    public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p,
               std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}
    double net_price(size_t cnt) const override
    {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
    protected:
    void debug() const override {
         std::cerr << "REQUESTED ON BULK_QUOTE\n";
         std::cerr << "Quote Sub-Object:\n";
         Quote::debug();
         std::cerr << "---\n";
        std:: cerr << "min_qty: " << min_qty << ", discount: " << discount << std::endl; 
    }
    private:
    std::size_t min_qty = 0; 
    double discount = 0.0;
};

class  Max_quote : public Quote {
    public:
    Max_quote() = default;
    Max_quote(std::string b, double p, std::size_t q, double d) : Quote(b, p), max_qty(q), discount(d) {}
    double net_price(std::size_t n) const override {
        return n > max_qty ? Quote::net_price(n) : n*((1-discount)*price); 
    }
    protected:
    void debug() const override {
         std::cerr << "REQUESTED ON MAX_QUOTE\n";
         std::cerr << "Quote Sub-Object:\n";
         Quote::debug();
         std::cerr << "---\n";
        std:: cerr << "max_qty: " << max_qty << ", discount: " << discount << std::endl; 
    }
    private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};*/


class Disc_quote : public Quote {
    public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double p,
               std::size_t q, double disc) : Quote(book, p), qty(q), discount(disc) { }
    virtual double net_price(size_t n) const = 0;
    protected:
    virtual void debug() const = 0;
    std::size_t qty = 0;
    double discount = 0.0;
};


class Bulk_quote : public Disc_quote
{
    public:
    
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);

    double net_price(size_t) const override;

    protected:
    void debug() const override; 
};

class  Max_quote : public Disc_quote{
    public:
    Max_quote() = default;
    Max_quote(std::string, double, std::size_t, double);
    double net_price(std::size_t) const override;
    protected:
    void debug() const override;
};

