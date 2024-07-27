#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your number : " << endl;
    cin >> n;
    if (n%3 == 0 && n%5 == 0)
    {
        cout << "Yes, this number is divisible by both 3 and 5" << endl;
    }
    else
    {
        cout << "It is not divisible by 3 and 5\n";
    }
    return 0;
}