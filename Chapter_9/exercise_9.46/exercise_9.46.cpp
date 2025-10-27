#include <iostream>
#include <string>

std::string format(std::string name, std::string prfx, std::string sfx)
{
    std::string subj = name;
    subj.insert(0, prfx);
    subj.insert(subj.size(), sfx);
    return subj;
}

int main()
{
    std::string name = "Tom";
    std::string prfx = "Mr. ";
    std::string sfx = " Jr.";
    std::cout << format(name, prfx, sfx);
}