#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;
void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q")
            break;
        print(std::cout, tq.query(s));
    }
}
int main()
{
    std::ifstream infile;
    std::string file_nme;
    while (!infile.is_open())
    {
        std::cout << "Please enter file name: ";
        std::cin >> file_nme;
        infile.open(file_nme);
    }
    runQueries(infile);
    infile.close();
}