#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findMinSumPosition(int arr[], int size, int length, int pos = 0, int minPos = 0, int minSum = INT_MAX, int currentSum = 0)
{
    if (pos + length > size) return minPos;

    if (currentSum == 0)
    {
        for (int i = pos; i < pos + length; i++)
        {
            currentSum += arr[i];
        }
    }

    if (currentSum < minSum)
    {
        minSum = currentSum;
        minPos = pos;
    }

    return findMinSumPosition(arr, size, length, pos + 1, minPos, minSum, currentSum - arr[pos] + (pos + length < size ? arr[pos + length] : 0));
}

int main()
{
    const int size = 100, length = 10;
    int arr[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 - 50;
    }

    int pos = findMinSumPosition(arr, size, length);
    cout << "Position of minimum sum sequence: " << pos << endl;

    return 0;
}
