// codeup 1818
#include <iostream>
using namespace std;

int gcd(int first, int second)
{
    if (second == 0)
        return first;
    return gcd(second, first % second);
}

int main()
{
    int first, second;
    while (scanf("%d %d", &first, &second) != EOF)
    {
        printf("%d\n", gcd(first, second));
    }
    return 0;
}