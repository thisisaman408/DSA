#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your number: " << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << " ";
        }
        for (int l = 1; l <= i; l++)
        {
            cout << "*";
        }
        for (int m = 1; m <= i - 1; m++)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
}
