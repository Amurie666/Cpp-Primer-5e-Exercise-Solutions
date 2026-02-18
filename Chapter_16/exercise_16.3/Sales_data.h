 #pragma once
#include <string>
#include <iostream>

struct Sales_data
{
    friend std::ostream &operator<<(std::ostream &f, Sales_data &dta);
    friend std::istream &operator>>(std::istream &f, Sales_data &dta);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
// Exercise 14.45.
    // std::string operator should return a string containing all data entries related to the underlying Sales_data object. 
    // This is useful if users were to develop external integrated applications that rely on fast
    // data retrieval. 
    explicit operator std::string() const {
        return isbn() + " " + std::to_string(units_sold) + " "
      + std::to_string(revenue) + " " + std::to_string(avg_price());
    }
    // double operator returns revenue.
    explicit operator double() const {
        return revenue;
    }
// -
    Sales_data &operator+=(const Sales_data &);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data & Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data temp(lhs);
    temp += rhs;
    return temp;
}

std::ostream &operator<<(std::ostream &f, const Sales_data &item)
{
    // Modified by Exercise 14.45.
        // Pre-Modified Code:
        /*
             f << item.isbn() << " " << item.units_sold << " "
            << item.revenue << " " << item.avg_price();
        */
    f << static_cast<std::string>(item);
    return f;
}

// Exercise 14.9.
std::istream &operator>>(std::istream &f, Sales_data &item)
{
    double price; 
    f >> item.bookNo >> item.units_sold >> price;
    if (f)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data(); 
    return f;
}


