#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;
    int r = 0;
    int lastDigit = 0;
    int b = n;
    while (n > 0)
    {
        r *= 10;
        lastDigit = n % 10;
        r += lastDigit;
        n /= 10;
    }
    cout << "The reverse order of the number " << b << " is " << r << endl;
}
/*
this is better approach to calculate reverse order of a number*/