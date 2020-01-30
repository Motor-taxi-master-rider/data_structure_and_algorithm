// B1013
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }

    int mid = (int)sqrt(1.0 * num);
    for (int i = 2; i < mid + 1; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
};

vector<int> countPrime(int end)
{
    vector<int> primes;
    int required = end;
    int number = 2;
    while (required != 0)
    {
        if (isPrime(number))
        {
            primes.push_back(number);
            required--;
        }
        number++;
    }

    return primes;
}

int main()
{
    int start, end;
    while (scanf("%d %d", &start, &end) != EOF)
    {
        if (start > end)
        {
            return -1;
        }
        vector<int> primes = countPrime(end);
        for (int i = start - 1; i < primes.size(); i++)
        {
            printf("%d ", primes[i]);
        }
    }
}