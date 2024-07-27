#include <iostream>
using namespace std;

int main()
{
    int n;
    char a;
    cout << "Do you want to print odd(o) or even(e) number : " << endl;
    cin >> a;
    cout << "Enter number up to which you want to print the even or odd numbers : " << endl;
    cin >> n;

    if (a == 'e')
    {
        cout << "Even numbers up to " << n << " are" << endl;
        for (int i = 0; i <= n; i += 2)
        {
            cout << i << endl;
        }
    }
    else if (a == 'o')
    {
        cout << "Odd numbers up to " << n << " are" << endl;
        for (int i = 1; i <= n; i += 2)
        {
            cout << i << endl;
        }
    }
    else
    {
        cout << "Invalid choice. Please enter 'o' for odd or 'e' for even." << endl;
    }

    return 0;
}
