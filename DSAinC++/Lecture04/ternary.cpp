//condition ? true : false; this is synax of ternary operator

#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter your number : " << endl;
    cin >> x;
    x % 2 == 0 ? cout << "Even" : cout << "odd";
    return 0;
}