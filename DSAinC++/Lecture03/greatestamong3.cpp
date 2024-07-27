/*here we have to find greatest among three numbers without using multiple conditions*/
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Enter first number : " << endl;
    cin >> a;
    cout << "Enter second number : " << endl;
    cin >> b;
    cout << "Enter third number : " << endl;
    cin >> c;
    if (a > b)
    {
        if (a > c)
        {
            cout << a << " is greatest among them" << endl;
        }
        else
        {
            cout << c << " is greatest among them all" << endl;
        }
    }
    else if (b > c)
    {
        if (b > a)
        {
            cout << b << " is greatest amomg them all" << endl;
        }
        else
        {
            cout << a << " is greatest among them all" << endl;
        }
    }
    else
    {
        cout << c << " is greatest among them all" << endl;
    }
}
