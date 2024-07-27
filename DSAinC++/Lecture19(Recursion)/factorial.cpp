#include <iostream>
using namespace std;

unsigned long long int factorial(unsigned long long  int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    unsigned long long  int fact = n * factorial(n - 1);
    return fact;
}
int main()
{
    unsigned long long  int n;
    cout << "Enter the number : ";
    cin >> n;
    unsigned long long  int x = factorial(n);
    cout << x;
}