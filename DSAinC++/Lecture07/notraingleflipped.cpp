#include <iostream>
using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter the no of rows : " << endl;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << " ";
//         }
//         for (int k = 1; k <= i; k++)
//         {
//             cout << k;
//         }
//         cout << endl;
//     }
// }

int main()
{
    int n;
    cout << "Enter the no of rows : " << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) >= n + 1)
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
/*SECOND ONE IS BETTER APPROACH WHICH IS BEING EXECUTED USING MATHS*/