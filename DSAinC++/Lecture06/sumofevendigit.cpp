#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your number : " << endl;
    cin >> n;
    int sum = 0;
    int a = n;
    while (n != 0)
    {
        a = n % 10;
        if (a % 2 == 0)
        {
            sum += a;
        }
        n = n / 10;
    }
    cout << "The sum of the even digits is : " << sum << endl;
}