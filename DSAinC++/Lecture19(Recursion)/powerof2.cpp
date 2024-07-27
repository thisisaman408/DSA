#include <iostream>
using namespace std;
bool powerof2(int n)
{
    if (n == 1)
    {
        return true;
    }
    else if (n % 2 == 0)
    {
        return powerof2(n / 2);
    }

    return false;
}
int main()
{
    int n;
    cout << "Enter the no : ";
    cin >> n;
    bool p = powerof2(n);
    cout<<p;
}