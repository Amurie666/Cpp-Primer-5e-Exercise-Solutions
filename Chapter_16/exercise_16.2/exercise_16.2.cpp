#include <string>
#include <cstring>
#include <iostream>
#include <array>

int compare(const char *arr1, const char *arr2)
{
    std::cerr << "CALLED compare(const char* arr1, const char* arr2);" << std::endl;
    return strcmp(arr1, arr2);
}
template <unsigned N, unsigned M>
int compare(const char (&arr1)[N], const char (&arr2)[M])
{
    std::cerr << "CALLED template<unsigned N, unsigned M> int compare(const char (&arr1)[N], const char (&arr2)[M]);" << std::endl;
    return strcmp(arr1, arr2);
}

template <typename T>
bool compare(const T &lhs, const T &rhs)
{
    std::cerr << "CALLED template<typename T> bool compare(const T& lhs, const T& rhs)" << std::endl;
    return lhs < rhs;
}
template <unsigned N>
class seq
{
public:
    seq(const std::array<int, N>& ar) : arr(ar) {}
    seq(const seq &) = delete;
    seq &operator=(const seq &) = delete;
    bool operator<(const seq &rhs) const
    {
        return avg() < rhs.avg();
    }
    int avg() const
    {
        if (N == 0)
            return 0;
        int sum = 0;
        for (int i{0}; i < N; i++)
            sum += arr[i];
        return sum / N;
    }

private:
    std::array<int, N> arr;
};

int main()
{
    const char word1[3] = {'H', 'i'};
    const char word2[5] = {'H', 'e', 'l', 'l', 'o'};
    std::array<int, 5> list1 = {1, 2, 3, 4, 5};
    std::array<int, 5> list2 = {1, 4, 5, 6, 7};
    seq<5> seq1(list1);
    seq<5> seq2(list2);
    std::cout << compare(seq1, seq2) << std::endl;
    std::cout << compare("Hi", "Hello") << std::endl;
    std::cout << compare<3, 5>(word1, word2) << std::endl;
}