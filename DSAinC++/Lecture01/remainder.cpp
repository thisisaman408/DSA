#include <iostream>
using namespace std;
int main()
{
    int a, b, q, r;
    cout << "Enter first number : " << endl;
    cin >> a;
    cout << "Enter second number : " << endl;
    cin >> b;
    q = a / b;
    r = a - (b * q);
    cout << "Your required remainder is : " << r << endl;
    return 0;
}