#include <iostream>
using namespace std;
int main()
{
    int x = 5;
    int *p = &x;
    cout << *p << endl;
    (*p)++; //that's how we increment the value stored at the address
    cout << *p;
}