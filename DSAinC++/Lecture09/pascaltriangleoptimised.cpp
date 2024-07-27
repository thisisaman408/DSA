#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the no of values : " << endl;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int k = n - 1; k >= i; k--)
        {

            
            cout << " ";
        }
        int curr = 1;
        for (int j = 0; j <= i; j++)
        {
            cout << curr << " ";
            curr = curr * (i - j) / (j + 1);
        }
        cout << endl;
    }
}
/*we uses simple a rule of combination which is
nC(r+1) = nCr * (n-r)/(r+1) 
here nCr is going to be 1 always, so we put curr = 1; and then we calculated 
next term as per above formula*/