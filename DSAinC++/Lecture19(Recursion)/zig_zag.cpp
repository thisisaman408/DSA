#include <iostream>
using namespace std;
void zigzag(int n)
{
    if (n == 0)
        return;
    cout << n;
    zigzag(n - 1);
    cout << n;
    zigzag(n - 1);
    cout << n;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        zigzag(i);
        cout << endl;
    }
}