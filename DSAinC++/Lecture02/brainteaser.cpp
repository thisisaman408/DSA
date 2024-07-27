#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter your character : " << endl;
    cin >> ch;
    cout << ((int)ch - 64);
    /*we did it because the ASCII value of A is 65, now if A is
    1 then we must subtract ASCII value of ch from 64 to get numbers*/
    
    return 0;
}