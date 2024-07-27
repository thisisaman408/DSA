#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter  your number : " << endl;
    cin >> n;
    if (n % 5 == 0 || n % 3 == 0)
    {
        if (n % 15 != 0)
        {
            if (n % 3 == 0)
            {
                cout << "This  number is divisible by 3 but not 15" << endl;
            }
            else if (n % 5 == 0)
            {
                cout << "This  number is divisible by 5 but not 15" << endl;
            }
        }
        else
        {
            cout << "This number is divisbibe by 3,5 and 15 too" << endl;
        }
    }
    else
    {
        cout << "This number is not divisilbe by 3,5 or 15" << endl;
    }
    return 0;
}