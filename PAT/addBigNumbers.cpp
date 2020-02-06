#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> addBigNumbers(vector<int> first, vector<int> second)
{
    vector<int> result, longNum, shortNum;
    if (first.size() > second.size())
    {
        longNum = first;
        shortNum = second;
    }
    else
    {
        longNum = second;
        shortNum = first;
    }

    int fillZero = longNum.size() - shortNum.size();
    for (int i = 0; i < fillZero; i++)
    {
        shortNum.push_back(0);
    }

    int carry = 0;
    for (int i = 0; i < longNum.size(); i++)
    {
        int sum = longNum[i] + shortNum[i] + carry;

        carry = sum / 10;
        sum = sum % 10;
        result.push_back(sum);
    }
    if (carry != 0)
    {
        result.push_back(carry);
    }

    return result;
};

vector<int> transfer(char num[])
{
    vector<int> result;
    int length = strlen(num);
    for (int i = length - 1; i > -1; i--)
    {
        result.push_back((int)(num[i] - '0'));
    }
    return result;
}

int main()
{
    char first[1000], second[1000];
    while (scanf("%s %s", &first, &second) != EOF)
    {

        vector<int> result = addBigNumbers(transfer(first), transfer(second));
        for (int i = result.size() - 1; i > -1; i--)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
