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
    int n;
    cout << "Enter your no of rows : " << endl;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int k = n - 1; k >= i; k--)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            int p = combination(i, j);
            cout << p << " ";
        }
        cout << endl;
    }
}
