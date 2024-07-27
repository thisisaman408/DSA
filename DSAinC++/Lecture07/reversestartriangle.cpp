#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of rows :";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
/*or you can use int j = 1; j <= n+1-i; j++ in 
sexcond nested loop*/