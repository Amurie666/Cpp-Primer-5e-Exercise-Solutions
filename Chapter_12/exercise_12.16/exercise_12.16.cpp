#include <memory>

int main()
{
    // Error: use of a deleted function.
    std::unique_ptr<int> q, w;
    q = w;
    std::unique_ptr<int> x = q;
    std::unique_ptr<int> y(q);
}