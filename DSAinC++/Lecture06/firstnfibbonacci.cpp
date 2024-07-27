#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    int a = 1;
    int b = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << "The 1st "<< " term of fibonacci is : " << 0 << endl;
            continue;
        }
        if (i == 2)

        {
            cout << "The 2nd" <<" term of fibonacci is : " << 1 << endl;
            continue;
        }
        int c = a + b;
        a = b;
        b = c;
        cout << "The " << i << " term of fibonacci is : " << c << endl;
    }
}
