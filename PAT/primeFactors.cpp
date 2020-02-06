// A1059

#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 100000;

struct Factor
{
    int num, count;
};

vector<int> getPrimes()
{
    vector<int> primes;
    int numbers[maxn] = {};
    for (int i = 2; i < maxn; i++)
    {
        if (numbers[i] == 0)
        {
            primes.push_back(i);
            for (int j = 2 * i; j < maxn; j += i)
            {
                numbers[j] = 1; // remove prime multiple
            }
        }
    }
    return primes;
}

vector<Factor> primeFactors(int num)
{
    int mid = (int)sqrt(1.0 * num);
    vector<int> primes = getPrimes();
    vector<Factor> factors;
    for (auto prime : primes)
    {
        if (prime > mid)
        {
            break;
        }
        if (num % prime == 0)
        {
            Factor factor;
            factor.num = prime;
            factor.count = 0;
            while (num % prime == 0)
            {
                factor.count++;
                num /= prime;
            }
            factors.push_back(factor);
        }
    }

    // When one num's factors is greater than sqrt(num)
    if (num != 1)
    {
        Factor factor;
        factor.num = num;
        factor.count = 1;
        factors.push_back(factor);
    }
    return factors;
}

int main()
{
    int input;
    while (scanf("%d", &input) != EOF)
    {
        if (input == 1)
        {
            cout << "1=1" << endl;
            continue;
        }
        vector<Factor> factors = primeFactors(input);
        for (int i = 0; i < factors.size(); i++)
        {
            if (i == 0)
            {
                cout << input << "=";
            }
            else
            {
                cout << "*";
            }
            cout << factors[i].num;
            if (factors[i].count > 1)
            {
                cout << "^" << factors[i].count;
            }
        }
        cout << endl;
    }
    return 0;
}