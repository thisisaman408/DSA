#include <iostream>
using namespace std;
int main()
{
    int a, d, n, an;
    cout << "Enter your first term : " << endl;
    cin >> a;
    cout << "Enter the common difference : " << endl;
    cin >> d;
    cout << "Enter the number of terms : " << endl;
    cin >> n;
    an = a + ((n - 1) * d);
    if (d > 0)
    {
        for (int i = a; i <= an; i += d)
        {
            cout << i << " ";
        }
    }
    else
    {
        for (int i = a; i >= an; i += d)
        {
            cout << i << " ";
        }
    }
    return 0;
}