#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of rows : " << endl;
    cin >> n;
    int m = n;
    int nsp = 1;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        cout << "*";
    }
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 1; j <= nsp; j++)
        {
            cout << " ";
        }
        nsp += 2;
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
