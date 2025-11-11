int main()
{
    int x = 5;
    auto increase_by_five = [x](int y)
    { return x + y; };
}