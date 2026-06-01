
#include <iostream>
#include <string>
#include <vector>

long long sum_str(const std::vector<std::string> &vec)
{
    long long sum = 0;
    for (const auto &elem : vec)
        sum += std::stoll(elem);
    return sum;
}

long double sum_str_fp(const std::vector<std::string> &vec)
{
    long double sum = 0.0L;
    for (const auto &elem : vec)
        sum += std::stold(elem);
    return sum;
}

int main()
{
    std::vector<std::string> sample = {"12f", "123.5f", "148.55f", "10.1f"};
    std::cout << "First test: " << (sum_str(sample) == (12 + 123 + 148 + 10) ? "success." : "failure.") << std::endl;
    std::cout << "Second test: " << (sum_str_fp(sample) == (12.0L + 123.5L + 148.55L + 10.1L) ? "success." : "failure.") << std::endl;
}