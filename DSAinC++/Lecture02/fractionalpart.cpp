/*in this question we have to caluclate the
fractional part of a number,like 9.7 should give output as 0.7*/
#include <iostream>
using namespace std;
int main()
{
    float x;
    cout << "Enter your number : " << endl;
    cin >> x;
    if (x < 0)
    {
        int y = (int)x - 1;
        cout << (y - x)<<endl;
    }
    else
    {
        cout << (x - (int)x)<<endl;
    }
}
/*fractional part is defined as number - greatest integer of number
 */