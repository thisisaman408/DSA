#include <iostream>
using namespace std;
int fibb(int n)
{
    if (n == 0 || n == 1|| n == 2)
    {
        return 1;
    }
    int p = fibb(n - 1) + fibb(n - 2);
    return p;
}
int main()
{
    int n;
    cin >> n;
    int p = fibb(n);
    cout << p;
}