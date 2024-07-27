#include <iostream>
using namespace std;
int no_of_set_bits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int no_of_flips(int a, int b)
{
    return no_of_set_bits(a ^ b);
}
int main()
{
    cout << no_of_flips(32, 12) << endl;
}