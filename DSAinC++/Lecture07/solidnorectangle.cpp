#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter no of rows :" << endl;
    cin >> n;
    cout << "Enter no of columns : " << endl;
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= m; i++)
        {

            cout << i;
        }
        cout << endl;
    }
}
