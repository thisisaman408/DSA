#include <iostream>
using namespace std;
void find(int n, int *x, int *y) // these x and y has address of firstDigit nd lastDigit
{
    *y = n % 10;  // condition to find last digit
    while (n > 9) // condition for first digit to find
    {
        n /= 10;
    }
    *x = n;
}
int main()
{
    int n;
    cin >> n;
    ;
    int firstDigit, lastDigit;
    int *p1 = &firstDigit;
    int *p2 = &lastDigit;
    find(n, p1, p2);
    cout << firstDigit << " " << lastDigit;
}