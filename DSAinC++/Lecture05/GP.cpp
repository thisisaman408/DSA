#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, r, n;
    float an;
    cout << "Enter first term " << endl;
    cin >> a;
    cout << "Enter common ratio : " << endl;
    cin >> r;
    cout << "Enter the number of terms upto which you want to print the numbers " << endl;
    cin >> n;
    if (r > 1)
    {
        an = a * ((pow(r, n) - 1) / r - 1);
    }
    else if (r < 1)
    {
        an = a * ((1 - pow(r, n)) / 1 - r);
    }
    for (int i = a; i <= an; i *= r)
    {
        cout << i << " ";
    }
    return 0;
}