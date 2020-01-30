// B1019
#include <iostream>
#include <algorithm>
using namespace std;

int *toArray(int num)
{
    if (num <= 0)
        throw - 1;
    int *numbers = new int[4]();
    for (int i = 0; i < 4; i++)
    {
        numbers[i] = num % 10;
        num /= 10;
    }

    return numbers;
}

int toNum(int arr[])
{
    int number = 0, base = 1000;
    for (int i = 0; i < 4; i++)
    {
        number += arr[i] * base;
        base /= 10;
    }
    return number;
}

int getSub(int num)
{
    int *arr = toArray(num);
    int reverse[4];
    int small = 0, large = 0;

    sort(arr, arr + 4);
    for (int i = i; i < 4; i++)
    {
        reverse[3 - i] = arr[i];
    }

    return toNum(reverse) - toNum(arr);
}

int main()
{
    int input;
    scanf("%d", &input);
    while (input != 6174)
    {
        input = getSub(input);
        cout << input << endl;
    }
    return 0;
}