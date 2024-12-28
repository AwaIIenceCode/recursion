#include <iostream>

using namespace std;

int rangeSum(int a, int b)
{
    if (a > b) return 0;
    return a + rangeSum(a + 1, b);
}

int main()
{
    int a, b;

    cout << "Enter the start of the range: ";
    cin >> a;

    cout << "Enter the end of the range: ";
    cin >> b;

    cout << "Sum of numbers: " << rangeSum(a, b) << endl;

    return 0;
}
