#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of rows : " << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}