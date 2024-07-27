#include <iostream>
using namespace std;
int main()
{
    int marks[10];
    cout << "Enter the marks : " << endl;
    for (int i = 0; i <= 9; i++)
    {
        cin >> marks[i];
    }
    for (int i = 0; i <= 9; i++)
    {
        if (marks[i] <= 35)
        {
            cout << i << endl;
        }
    }
}