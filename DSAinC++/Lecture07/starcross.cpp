#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of rows : " << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == i || i + j == n + 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/*
yaad krna padega or thoda sa logic lagana padega..
actually yahaa..
1 *   *
2  * * 
3   *  
4  * * 
5 *   * 
here for first diagonal, the simple is if i == j to
* print krdo, and for second diagonal, if i+j ==1 to
star print kardo...
*/