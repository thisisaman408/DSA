#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number whose table you want to print" << endl;
    cin >> n;
    for (int i = n; i <= 10 * n; i += n)
    {
        cout << i << endl;
    }
    return 0;
}