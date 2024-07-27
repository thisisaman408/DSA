#include <iostream>
using namespace std;
int countWays(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else
    {
        return (countWays(n - 1) + countWays(n - 2) + countWays(n - 3));
    }
}
int main()
{
    int n;
    cout << "Enter no of stairs :";
    cin >> n;
    int p = countWays(n);
    cout << p;
}