#include <iostream>
using namespace std;
int factorial(int n)
{

    int a = 1;
    for (int i = 1; i <= n; i++)
    {
        a = a * i;
    }
    return a;
}
int permutation(int n, int r)
{
    int x = factorial(n);
    int y = factorial(n - r);
    return x / y;
}
int combination(int n, int r)
{
    int d = permutation(n, r);
    int e = factorial(r);
    int g = d / e;
    return g;
}

int main()
{
    int a;
    cout << "Enter your choice : " << endl;
    cout << "1) Permutation" << endl
         << "2) Combination" << endl
         << "3) Exit" << endl;
    cin >> a;
    if (a == 1)
    {
        int n, r;
        cout << "Enter the value of n : ";
        cin >> n;
        cout << "Enter the value of r : ";
        cin >> r;
        int p = permutation(n, r);
        cout << "The permutation of " << n << " and " << r << " is " << p << endl;
    }
    else if (a == 2)
    {

        int n, r;
        cout << "Enter the value of n : ";
        cin >> n;
        cout << "Enter the value of r : ";
        cin >> r;
        int p = combination(n, r);
        cout << "The combination of " << n << " and " << r << " is " << p << endl;
    }
    else
    {
        cout << "Thanks for using our program to calculate permutation and combination" << endl;
    }
    return 0;
}
