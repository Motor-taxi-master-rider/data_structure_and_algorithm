#include <random>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
default_random_engine e;

int randPartition(vector<int> &arr, int start, int end)
{
    uniform_int_distribution<unsigned> u(start, end);
    int select = u(e); // select index from [start, end]
    swap(arr[start], arr[select]);
    int tmp = arr[start];
    while (start < end)
    {
        while (start < end && arr[end] > tmp)
            end--;
        arr[start] = arr[end];
        while (start < end && arr[start] <= tmp)
            start++;
        arr[end] = arr[start];
    }
    arr[start] = tmp;
    return start;
}

int randomSelect(vector<int> &arr, int start, int end, int index)
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
    vector<int> input = {1, 6, 33, 18, 4, 0, 10, 5, 12, 7, 2, 9, 3};
    int result = randomSelect(input, 0, input.size() - 1, 9); // 9

    cout << result << endl;

    return 0;
}