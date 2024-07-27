#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Enter first number " << endl;
    cin >> a;
    cout << "Enter second number " << endl;
    cin >> b;
    cout << "Enter third number " << endl;
    cin >> c;
    if ((a + b > c) && (a + c > b) && (c + b > a))
    {
        cout << a<<","<<b << " and " << c << " can form a triangle" << endl;
    }
    else
    {
        cout << "Triangle cannot be form from the values input" << endl;
    }
    return 0;
}