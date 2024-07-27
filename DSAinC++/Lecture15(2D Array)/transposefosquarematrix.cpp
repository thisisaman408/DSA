#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array : " << endl;
    cin >> n;
    int a[n][n];
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    // transpose in same matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // when we traverse the array from j = 0, to elements 2 baar swap ho jate hai
        {

            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    cout << "Your transposed matrix " << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}