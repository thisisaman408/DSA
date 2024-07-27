#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;
    if (n >= 0)
    {
        if (n % 5 == 0)
        {
            cout << "Yes! it is divisible by 5" << endl;
        }
        else
        {
            cout << "It is not divisible by 5";
        }
    }
    else
    {
        cout << "Please enter a positive integer" << endl;
    }

    return 0;
}