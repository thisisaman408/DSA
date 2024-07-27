#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your on of rows : " << endl;
    cin >> n;
    int nst = 1;
    int nsp = n - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= nsp; j++)
        {
            cout << " ";
        }
        nsp--;
        for (int k = 1; k <= nst; k++)
        {
            cout << "*";
        }
        nst += 2;
        cout << endl;
    }
}

/* nst means no of stars in each line
nsp means no of spaces in each line
har line m n -1 spaces hain, so nsp ko n - 1 se initialise krke
nsp-- karege...
and stars are in odd numbers...so
nst ko 1 se initialise krke nst += 2 kar denge..
this is our plan*/
/*this  is better approach to solve this type of questions*/