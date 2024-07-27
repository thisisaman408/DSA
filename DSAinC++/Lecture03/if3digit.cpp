#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your number : " << endl;
    cin >> n;
    if (n >= 100 && n <= 999)
    {
        cout << "Yes it is a 3 digit  number\n";
    }
    else
    {
        cout << "No, it is not a 3 digit  number\n";
    }
    return 0;
}