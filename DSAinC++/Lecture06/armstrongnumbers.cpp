#include <iostream>
#include <cmath>
using namespace std;
bool armstrong(int num)
{
    int originalnumber = num;
    int numdigits = 0;
    int sum = 0;
    while (originalnumber != 0)
    {
        originalnumber /= 10;
        numdigits++;
    }
    originalnumber = num;
    int a = 0;
    while (originalnumber != 0)
    {
        a = originalnumber % 10;
        sum += pow(a, numdigits);
        originalnumber /= 10;
    }
   return (sum == num);
}
int main()
{
    int n;
    cout << "Enter your limit" << endl;
    cin >> n;
    for (int i = 10; i <= n; i++)
    {
        if (armstrong(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}

/* starting from 10, as 1 -9 are trivial armstrong number*/
