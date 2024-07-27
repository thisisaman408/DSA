#include <iostream>
using namespace std;
void gcd(int x, int y)
{
    bool flag = false;
    int gcd = 1;
    for (int i = min(x, y); i >= 1; i--)
    {
        if (x % i == 0 && y % i == 0)
        {
            gcd = i;
            break;
        }
    }
    cout << "the value of gcd  : " << gcd << endl;
}

int main()
{
    int a, b;
    cout << "Enter the value of a : ";
    cin >> a;
    cout << "Enter the value of b : ";
    cin >> b;
    gcd(a, b);
}
