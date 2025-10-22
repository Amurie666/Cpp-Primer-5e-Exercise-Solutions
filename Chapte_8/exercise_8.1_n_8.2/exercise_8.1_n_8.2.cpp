#include <iostream>
#include <string>

std::istream& read(std::istream& istrm, std::ostream& ostrm) {
    std::string x;
    while(istrm >> x)
        ostrm << x << " ";
    istrm.clear();
    return istrm;
}

int main() {
    read(std::cin, std::cout);
    return 0;
}