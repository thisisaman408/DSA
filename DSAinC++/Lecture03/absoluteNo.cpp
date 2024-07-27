#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;
    if (n < 0) {
        n = -n;
    }
    cout << n <<endl;
    return 0;
}