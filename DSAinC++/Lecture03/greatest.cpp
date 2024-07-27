#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    cout << "Enter 3 numbers : " << endl;
    cin >> x >> y >> z;
    if (x != y && x != z && y != z)
    {
        if (x > y && x > z)
        {
            cout << x << " is greatest among them" << endl;
        }
        else if (y > x && y > z)
        {
            cout << y << " is greatest among them" << endl;
        }
        else
        {
            cout << z << " is the greatest among them" << endl;
        }
    }
    else
    {
        if (x == y && x > z)
        {
            cout << x << " and " << y << " are equal"
                 << " and " << x << " is greatest among them" << endl;
        }
        else if (x == y && x < z)
        {
            cout << x << " and " << y << " are equal"
                 << " and " << z << " is greatest among them" << endl;
        }
        else if (x == z && y > z)
        {
            cout << x << " and " << z << " are equal"
                 << " and " << y << " is greatest among them" << endl;
        }
        else if (x == z && y < z)
        {
            cout << x << " and " << z << " are equal"
                 << " and " << z << " is greatest among them" << endl;
        }
        else if (y == z && x > z)
        {
            cout << z << " and " << y << " are equal"
                 << " and " << x << " is greatest among them" << endl;
        }
        else if (z == y && x < z)
        {
            cout << z << " and " << y << " are equal"
                 << " and " << z << " is greatest among them" << endl;
        }
    }
    return 0;
}