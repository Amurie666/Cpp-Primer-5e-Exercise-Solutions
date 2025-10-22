#include <iostream>
#include <fstream>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        std::ifstream input(argv[1]);
        std::ofstream output(argv[2]);
        if (input && output)
        {
            Sales_data total;

            if (read(input, total))
            {
                Sales_data trans;
                while (read(input, trans))
                {
                    if (total.isbn() == trans.isbn())
                        total.combine(trans);
                    else
                    {
                        print(output, total) << std::endl;
                        total = trans;
                    }
                }
                print(output, total) << std::endl;
            }
            else
                std::cerr << "No data?!" << std::endl;
        }
        else
        {
            std::cerr << "Input or Output file not found." << std::endl;
        }
    }
    else
        std::cerr << "No arguments passed." << std::endl;
    return 0;
}