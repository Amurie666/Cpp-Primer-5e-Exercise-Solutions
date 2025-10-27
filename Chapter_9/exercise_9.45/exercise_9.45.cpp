#include <iostream>
#include <string>

std::string format(std::string name, std::string prfx, std::string sfx)
{
    std::string subj = name;
    subj.insert(subj.begin(), prfx.begin(), prfx.end());
    subj.append(sfx.begin(), sfx.end());
    return subj;
}

int main()
{
    std::string name = "Tom";
    std::string prfx = "Mr. ";
    std::string sfx = " Jr.";
    std::cout << format(name, prfx, sfx);
}