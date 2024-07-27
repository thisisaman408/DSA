#include <iostream>
using namespace std;
int main()
{
    int x;

    int a;
    bool flag = true;
    char b;
    do
    {
        cout << "Enter a number" << endl;
        cin >> x;
        for (int i = 2; i <= (x - 1); i++)
        {
            a = x % i;
            if (a == 0)
            {
                flag = false;
                break;
            }
        }
        if (x == 1 or x == 0)
        {
            cout << x << " is  neither prime nor composite" << endl;
        }
        else if (flag == true)
        {
            cout << x << " is a prime number" << endl;
        }

        else
        {
            cout << x << " is a composite number" << endl;
        }
        cout << "Would you like to check another number too ?" << endl;
        cin >> b;
    } while (b == 'Y' or b == 'y' or b == '1');
}
