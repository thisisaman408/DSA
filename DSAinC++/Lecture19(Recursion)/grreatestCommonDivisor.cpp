#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b % a == 0)
    {
        return a;
    }

    return gcd(b % a, a);
}
int main()
{
    int a, b;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    int c = gcd(a, b);
    cout << c;
}
// tc is O(log(a + b), which is calculated using induction