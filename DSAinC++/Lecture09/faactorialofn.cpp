#include <iostream>
using namespace std;
void factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        cout << i << " = " << fact << endl;
    }
}
int main()
{

    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    factorial(n);
}