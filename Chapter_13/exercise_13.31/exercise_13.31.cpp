// Fun exercise!
/*
 * swap() has never been called in this example, which had me confused because
 * I assumed std::sort() invokes swap() when sorting ranges, but after
 * doing some research it seems that std::sort() will remove the call to swap()
 * for short ranges and preserve it for longer ranges instead.
 */

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

class HasPtr
{
public:
    friend std::ostream &operator<<(std::ostream &, const HasPtr &);
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr &, const HasPtr &);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    // For conversion
    HasPtr(const char *arr) : HasPtr(std::string(arr)) {}
    HasPtr &operator=(const HasPtr &rhs)
    {
        std::string temp = *rhs.ps;
        delete ps;
        ps = new std::string(temp);
        i = rhs.i;
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

std::ostream &operator<<(std::ostream &out, const HasPtr &hp)
{
    out << "value: " << *hp.ps << "; index: " << hp.i << "; loc: " << hp.ps;
    return out;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    std::cout << "Swapping {" << lhs << "} with {" << rhs << "}" << std::endl;
    swap(lhs.ps, rhs.ps);
    std::swap(lhs.i, rhs.i);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}

int main()
{
    std::cout << "\t VECTOR 1" << std::endl;
    std::vector<HasPtr> vec = {"Knife", "Electric", "Eel", "Red", "Wooden", "Bull", "Push", "Antagonist"};
    std::sort(vec.begin(), vec.end()); // Does not call swap().
    for (const auto &elem : vec)
        std::cout << "{" << elem << "}" << std::endl;
    std::cout << "\t VECTOR 2" << std::endl;
    // Words chosen randomly.
    std::vector<HasPtr> vec1 = {
        "Knife",
        "Electric",
        "Eel",
        "Red",
        "Wooden",
        "Bull",
        "Push",
        "Antagonist",
        "Nature",
        "Dominant",
        "Eel",
        "Forfeit",
        "Pompous",
        "Exquisite",
        "Excavate",
        "Mortal",
        "Joyful",
        "Gleeful",
        "Exuberate",
        "Cholera",
        "Hive",
        "Elopement",
        "Tranquil",
        "Meek",
    };
    std::sort(vec1.begin(), vec1.end()); // Longer range; calls swap().
    for (const auto &elem : vec1)
        std::cout << "{" << elem << "}" << std::endl;
}