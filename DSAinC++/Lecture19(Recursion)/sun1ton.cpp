// without any extra parameter
#include <iostream>
using namespace std;
int summ(int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    int sum = n + summ(n - 1);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int p = summ(n);
    cout << p;
}