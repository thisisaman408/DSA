#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your percentage" << endl;
    cin >> n;
    if (n >= 91 && n <= 100)
    {
        cout << "Excellent work !" << endl;
    }
    else if (n >= 81 && n <= 91)
    {
        cout << "Very good !" << endl;
    }
    else if (n >= 71 && n <= 81)
    {
        cout << "Good !" << endl;
    }
    else if (n >= 61 && n <= 71)
    {
        cout << "Can do better !" << endl;
    }
    else if (n >= 51 && n <= 61)
    {
        cout << "Average !" << endl;
    }
    else if (n >= 41 && n <= 51)
    {
        cout << "below average!" << endl;
    }
    else
    {
        cout << "Fail !" << endl;
    }
    return 0;
}