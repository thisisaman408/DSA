#include <iostream>
using namespace std;
int main()
{
    int x;
    int i = 1;
    cout << "Enter number of subjects" << endl;
    cin >> x;
    float y[x];
    while (i <= x)
    {
        cout << "Enter marks in this subject : " << endl;
        cin >> y[i];
        i++;
    }
    float sum = 0;
    i = 1;
    while (i <= x)
    {
        sum = sum + y[i];
        i++;
    }
    float percentage;
    percentage = sum / x;
    cout << "Hence the required percentage of " << x << " subjects is : " << percentage << endl;
    return 0;
}