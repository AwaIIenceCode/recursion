#include <iostream>

using namespace std;

void printStars(int n)
{
    if (n > 0)
    {
        cout << "*";
        printStars(n - 1);
    }
}

int main()
{
    int n;

    cout << "Enter the number of stars: ";
    cin >> n;

    printStars(n);

    cout << endl;

    return 0;
}
