#include "StrBlobPtr.h"
#include <fstream>
#include <iostream>
void read_blob(std::ifstream &input, StrBlob &blb)
{
    std::string line;
    while (getline(input, line))
        blb.push_back(line);
}

void print_blob(const StrBlob &blb, std::ostream &out)
{
    int i{0};
    C_StrBlobPtr it = blb.beg();
    while (i < blb.size())
    {
        out << it.deref() << std::endl;
        i++;
        it.incr();
    }
}

int main()
{
    std::ifstream file;
    std::string file_nme;
    while (!file.is_open())
    {
        std::cout << "\t Enter File Name: ";
        std::cin >> file_nme;
        std::cout << std::endl;
        file.open(file_nme);
    }
    StrBlob text;
    read_blob(file, text);
    std::ofstream out;
    while (!out.is_open())
    {
        std::cout << "\t Enter Output File Name: ";
        std::cin >> file_nme;
        out.open(file_nme);
    }
    print_blob(text, out);
    file.close();
    out.close();
    bool exist = false;
    while (!exist)
    {
        std::cout << "Exist? 1 (yes); 0 (no)." << std::endl;
        std::cin >> exist;
    }
}