#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your number: " << endl;
    cin >> n;
    int nst = 1;
    int nsp = n - 1;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= nsp; j++)
        {
            cout << " ";
        }
        (i <= n - 1) ? nsp-- : nsp++;
        for (int k = 1; k <= nst; k++)
        {
            cout << "*";
        }
        (i <= n - 1) ? nst += 2 : nst -= 2;
        cout << endl;
    }
}