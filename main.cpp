#include <iostream>

using namespace std;

int findMax(int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

int findMax(int arr[][3], int rows, int cols)
{
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > maxVal) maxVal = arr[i][j];
        }
    }
    return maxVal;
}

int findMax(int arr[][3][3], int depth, int rows, int cols)
{
    int maxVal = arr[0][0][0];
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                if (arr[i][j][k] > maxVal) maxVal = arr[i][j][k];
            }
        }
    }
    return maxVal;
}

int findMax(int a, int b)
{
    return (a > b) ? a : b;
}

int findMax(int a, int b, int c)
{
    return findMax(a, findMax(b, c));
}

int main()
{
    int arr1[] =
            {1, 2, 3, 4, 5};
    cout << "Max in 1D array: " << findMax(arr1, 5) << endl;

    int arr2[3][3] =
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Max in 2D array: " << findMax(arr2, 3, 3) << endl;

    int arr3[2][3][3] =
            {
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}}
    };

    cout << "Max in 3D array: " << findMax(arr3, 2, 3, 3) << endl;

    cout << "Max of two numbers: " << findMax(10, 20) << endl;
    cout << "Max of three numbers: " << findMax(10, 20, 30) << endl;

    return 0;
}
