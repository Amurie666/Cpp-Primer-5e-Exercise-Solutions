#include <iostream>
#include <map>
#include <set>
#include <string>

int main()
{
    std::multimap<std::string, std::set<std::string>> author_works = {{"Mark", {"The Justification of a Brutal Existence", "Beyond Reason"}},
                                                                      {"Bloch", {"The Real Numbers and Real Analysis", "Proofs and the Fundamentals", "I do be casing!"}}};
    std::string query;
    do
    {
        std::cin >> query;
        auto it = author_works.find(query);
        if (it == author_works.end())
            std::cout << "Woops. Tell me about it!" << std::endl;
        else
        {
            author_works.erase(it);
            std::cout << "Erased." << std::endl;
        }
        for (const auto &elem : author_works)
        {
            std::cout << elem.first << ": ";
            for (const auto &v : elem.second)
                std::cout << v << " ## ";
            std::cout << std::endl;
        }
    } while (true);
}