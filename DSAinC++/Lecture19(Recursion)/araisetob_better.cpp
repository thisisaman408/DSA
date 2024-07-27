/* here we will be talking about, a^b ,we calculated it, as
a*power(a,b -1), which increases it's time complexity to next level, from
now on, we will, a^b/2, and so on, if it is an odd power, then we will multiply it with a a again */

#include <iostream>
using namespace std;
int power(int a, int b)
{

    if (b == 1)
    {
        return a;
    }

    if (b % 2 == 0)
    {
        int ans = power(a, b / 2);
        return (ans * ans);
    }
    int ans = power(a, b / 2);
    return ans * ans * a;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int p = power(a, b);
    cout << p;
}