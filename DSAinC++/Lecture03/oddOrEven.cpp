#include <iostream>
using namespace std;
int main()
{
    int n;
    char x;

    do
    {
        cout << "Enter an integer : " << endl;
        cin >> n;

        {
            if (n % 2 == 0)
            {
                cout << "It is an even number" << endl;
            }
            else
            {
                cout << "It is an odd number";
            }
            cout << "\nWanna check another number?";
            cin >> x;
        }
    } while (x == 'y');
    return 0;
}