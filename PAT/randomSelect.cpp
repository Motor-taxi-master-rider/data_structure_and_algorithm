#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 100010;

int randPartition(int arr[], int start, int end)
{
    int select = round(1.0 * rand() / RAND_MAX * (end - start)) + start;
    swap(arr[start], arr[select]);
    int tmp = arr[start];
    while (start < end)
    {
        while (start<end && arr[end]> tmp)
            end--;
        arr[start] = arr[end];
        while (start < end && arr[start] <= tmp)
            start++;
        arr[end] = arr[start];
    }
    arr[start] = tmp;
    return start;
}

int randomSelect(int arr[], int start, int end, int index)
{
    if (start > end)
        return -1;
    int pos = randPartition(arr, start, end);
    int M = pos - start + 1; // left, right区间中的第M位
    if (M == index)
        return arr[pos];
    else if (M > index)
    {
        return randomSelect(arr, start, pos - 1, index);
    }
    else if (M < index)
    {
        return randomSelect(arr, pos + 1, end, index - M);
    }
}

int main()
{
    int A[] = {1, 6, 33, 18, 4, 0, 10, 5, 12, 7, 2, 9, 3};
    int length = sizeof(A) / sizeof(int);
    int result = randomSelect(A, 0, length - 1, 9);

    cout <<result << endl;

    return 0;
}