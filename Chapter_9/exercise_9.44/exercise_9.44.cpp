#include <iostream>
#include <string>

bool replace(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    if (oldVal.empty())
        return false;
    bool success = false;
    for (size_t i = 0; i <= s.size() - oldVal.size();)
    {
        if (s.substr(i, oldVal.size()) == oldVal)
        {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
            success = true;
        }
        else
        {
            ++i;
        }
    }
    return success;
}

int main()
{
    std::string sample = "The evidence you're looking for is not here tho. You should probably look thru the files given to you by ur lawyer.";
    std::cout << "The sample before calling replace(): " << sample << std::endl;
    replace(sample, "tho.", "though.");
    replace(sample, "thru", "through");
    replace(sample, "ur", "your");
    replace(sample, "non-existent test word", "test");
    std::cout << "After calling replace(): " << sample << std::endl;
}