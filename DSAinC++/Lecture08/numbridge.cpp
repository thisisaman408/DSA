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
        cout << i;
    }
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        int a = 1;
        for (int j = 1; j <= n - i; j++)
        {
            cout << a;
            a++;
        }
        // spaces
        for (int j = 1; j <= nsp; j++)
        {
            cout << " ";
            a++;
        }
        nsp += 2;
        for (int j = 1; j <= n - i; j++)
        {
            cout << a;
            a++;
        }

        cout << endl;
    }
}
/* yaha pe bus...a ko extra space times or increment krna hai*/