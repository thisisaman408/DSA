#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter first number : " << endl;
    cin >> a;
    cout << "Enter second number : " << endl;
    cin >> b;
    int r = a % b; // modulo operator which gives remainder of two functions used
    cout << "Your required remainder is : " << r << endl;
    return 0;
}