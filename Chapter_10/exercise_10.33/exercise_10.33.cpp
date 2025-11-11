#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

int main() {
    std::string fname;
    std::ofstream otf1 ("output_file1_odd.txt");
    std::ofstream otf2 ("output_file2_even.txt");
    std::ifstream inf;
    std::ostream_iterator<int> oit1(otf1, " "), oit2(otf2, "\n");
    do {
        std::cout << "Enter valid input file name: ";
        std::cin >> fname;
        inf.open(fname);
        std::cout << std::endl;
    } while(!inf.is_open());
    std::istream_iterator<int> init(inf), eof;
    while(init != eof) {
        if(*init % 2)
            oit1 = *init;
        else 
            oit2 = *init;
        ++init;
    }
    return 0;
}