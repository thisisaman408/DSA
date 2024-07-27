#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter your number : " << endl;
    cin >> x;
    int sum = 0;
    int a = x;
    int b = x;
    while (x > 0)
    {
        a = x % 10;
        x /= 10;
        sum += a;
    }
    cout << "The sum of the digits in the number " << b << " is " << sum << endl;
}