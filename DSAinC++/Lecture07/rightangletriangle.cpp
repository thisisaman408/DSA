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
            cout << "*";
        }
        cout << endl;
    }
}
/*yha pr basically if you see, no of stars are just
equal to the no of rows, in 1st row one star in second row
2 star and so on and no of rows are i, so we made a nested
loop which is iteratint till it reached i, for 1st row i is
1,so it iterates only once, for i = 2 it iterates only twice and that's what we 
want, cause after each complete iteration there's an enter*/