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
            cout << l;
        }
        for (int m = i - 1; m >= 1; m--)
        {
            cout << m;
        }
        cout << endl;
    }
}