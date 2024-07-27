#include <iostream>
using namespace std;
int main()
{
    float cp, sp;
    cout << "Enter cost price : " << endl;
    cin >> cp;
    cout << "Enter selling price : " << endl;
    cin >> sp;
    float proOrloss;
    proOrloss = sp - cp;
    if (proOrloss < 0)
    {
        cout << "There is a loss of : " << -proOrloss << endl;
    }
    else
    {
        cout << "There is a profit of : " << proOrloss << endl;
    }
    return 0;
}