#include <iostream>
using namespace std;
int main()
{
    int x = 4;
    int *p = &x;
    int **ptr = &p;
    cout << x << endl;     // 4
    cout << *p << endl;    // 0x16b5ff44c
    cout << **ptr << endl; // 0x16b5ff440

}