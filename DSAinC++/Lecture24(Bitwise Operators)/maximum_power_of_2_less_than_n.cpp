#include <iostream>
using namespace std;
int smallest_power_of_2(int n)
{
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if ((1 << i) < n)
            continue;
        else
        {
            p = (1 << (i - 1));
            break;
        }
    }
    return p;
}

int brian_method_for_same(int n)
{
    int temp;
    while (n != 0)
    {
        temp = n;
        n = n & (n - 1);
    }
    return temp;
}

int better_method_for_same(int n)
{
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    return (n + 1) >> 1;
}

int main()
{
    cout << smallest_power_of_2(100) << endl;
    cout << brian_method_for_same(22) << endl;
    cout << better_method_for_same(12) << endl;
}