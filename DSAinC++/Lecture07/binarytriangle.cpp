#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of rows :" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }

        cout << endl;
    }
}

/*here as you can see, when i and j both are odd or even only then it is 1
else it is zero, and as per basic maths we know if two numbers are odd or they are even
their sum is always even*/