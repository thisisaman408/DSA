#include <iostream>
using namespace std;
int main()
{
    int t = 10;
    while (t /= 2)
    {
        cout << "HEllo" << endl;
    }
}

/*here we assigned the value to t = 10, but as you can see here
we have assigned the value to t under conditonal too
while (condition) this is not a condition but assigning a value to it*/