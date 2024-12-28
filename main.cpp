#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

template <typename T>
void initializeMatrix(T** matrix, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = static_cast<T>(rand() % 10);
        }
    }
}

template <typename T>
void printMatrix(T** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void findMinMaxDiagonal(T** matrix, int size, T& min, T& max)
{
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 0; i < size; i++)
    {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

template <typename T>
void sortRows(T** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        sort(matrix[i], matrix[i] + size);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;

    int** intMatrix = new int*[size];
    for (int i = 0; i < size; i++) intMatrix[i] = new int[size];

    initializeMatrix(intMatrix, size);
    cout << "Integer Matrix:\n";
    printMatrix(intMatrix, size);

    int intMin, intMax;
    findMinMaxDiagonal(intMatrix, size, intMin, intMax);
    cout << "Integer Matrix Diagonal Min: " << intMin << ", Max: " << intMax << endl;

    sortRows(intMatrix, size);
    cout << "Sorted Integer Matrix:\n";
    printMatrix(intMatrix, size);

    for (int i = 0; i < size; i++) delete[] intMatrix[i];
    delete[] intMatrix;

    return 0;
}
