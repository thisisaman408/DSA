#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your number : " << endl;
    cin >> n;
    int lastDigit = 0;
    int b = n;
    while (n > 0)
    {
        lastDigit = n % 10;
        cout<< lastDigit;
        n = n/10;
    }
}

/*this is not a good approach, find another code which is a better approach
to solve this question*/