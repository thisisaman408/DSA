//* this is deference operator
#include <iostream>
using namespace std;
int main()
{
    int x = 33;
    int *p = &x;
    x = 90;// this is the power, after reassignig the value the value
    // inside the varible changes but address of variable remains same
    //so we are able to print that value with the help of pointer 
    //this is somehow like renters
    cout << *p;
}
// we can also update or assign the value to x as *p, as this deference operator
//means, value at the address