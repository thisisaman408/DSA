#include <iostream>
using namespace std;
bool isPowerOfThree(int n)
{
    if (n <= 0)
        return false;
    while (n % 3 == 0)
    {
        n /= 3;
    }
    return n == 1;
}

int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (isPowerOfThree(num))
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return 0;
}
