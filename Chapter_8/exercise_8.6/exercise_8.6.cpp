#include <iostream>
#include <fstream>
#include "Sales_data.h"

int main(int argc, char* argv[])
{
    std::ifstream in_file(argv[1]);
    std::ofstream out_file(argv[2]);
    if(in_file && out_file) {
    Sales_data total;
    double price;
    if (in_file >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (in_file >> trans.bookNo >> trans.units_sold >> price)
        {
            trans.revenue = trans.units_sold * price;
            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                out_file << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        out_file << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
    }
    else
    {
        std::cerr << "Invalid data or end of file." << std::endl;
        in_file.close();
        out_file.close();
        return -1;
    }
} else {
    std::cerr << "Input or Output file not found." << std::endl;
    in_file.close();
    out_file.close();
}
    return 0;
}