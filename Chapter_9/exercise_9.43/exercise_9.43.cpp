#include <iostream>
#include <string>

bool is_oldVal(const std::string &oldVal, const std::string::iterator &beg_r)
{
    for (auto it = oldVal.begin(); it != oldVal.end(); it++)
    {
        if (*(beg_r + (it - oldVal.begin())) != *it)
            return false;
    }
    return true;
}

bool replace(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    bool success = false;
    if (oldVal.size() > 0 && oldVal.size() <= s.size())
    {
        for (auto beg_r = s.begin(), end_r = beg_r + oldVal.size() - 1; end_r != s.end(); beg_r++, end_r++)
        {
            if (is_oldVal(oldVal, beg_r))
            {
                auto insrt_it = s.erase(beg_r, end_r + 1);
                beg_r = s.insert(insrt_it, newVal.begin(), newVal.end()) + newVal.size();
                end_r = beg_r + oldVal.size() - 1;
                success = true;
            }
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