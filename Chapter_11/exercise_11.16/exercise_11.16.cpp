#include <map>
#include <string>

int main()
{
    std::string name;
    std::map<std::string, int> ppl_age;
    std::map<std::string, int>::iterator it = ppl_age.begin();
    if (it == ppl_age.end())
        ppl_age["Mark"] = 20;
    it->second = 10;
}