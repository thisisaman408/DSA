#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cout<<endl;
    while (t--)
    {
        int x1, x2, x3, a;
        cin >> x1 >> x2 >> x3;
        while (x1 > x2 || x2 > x3 || x1 > x3)
        {
            if (x1 > x2)
            {
                int temp = x1;
                x1 = x2;
                x2 = temp;
            }
            if (x2 > x3)
            {
                int temp = x2;
                x2 = x3;
                x3 = temp;
            }
            if (x1 > x3)
            {
                int temp = x1;
                x1 = x3;
                x3 = temp;
            }
        }
        a = x2;
        int d1 = abs(x1 - a);
        int d2 = abs(x3 - a);
        cout << (d1 + d2);
        cout << endl;
    }
}
