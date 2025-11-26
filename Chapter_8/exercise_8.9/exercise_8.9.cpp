#include <iostream>
#include <vector>
#include <string>
#include<sstream>

std::istream& read(std::istream& istrm, std::ostream& ostrm) {
    std::string x;
    while(istrm >> x)
        ostrm << x << " ";
    istrm.clear();
    return istrm;
}

int main(int argc, char **argv)
{
    std::string line;
    std::cout << "Insert a line: ";
    std::getline(std::cin, line);
    std::istringstream line_strm (line);
    read(line_strm, std::cout);
}