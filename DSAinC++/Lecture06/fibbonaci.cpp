#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter term number : " << endl;
    cin >> n;
    int num1 = 1;
    int num2 = 1;
    int term;
    if (n == 1 || n == 2)
    {
        cout << "The term  is " << 1 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int p = 2;
            int q = i + p;
            term = p + q;
        }
    }
    cout << "The term is : " << term << endl;
}
