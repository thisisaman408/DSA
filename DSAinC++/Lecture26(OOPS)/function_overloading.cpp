/*

Function Overloading is related to polymorphism
it means, creataing functinons with same name but different parameters
*/
#include <iostream>
using namespace std;
void add(int a, int b)
{
    cout << a + b << endl;
}
void add(int a)
{
    cout << 10 + a << endl;
}
//two functions, with same name,but different parameters are allowed in C++ and Java
//this is an example of function overloading and compile time polymorphism
int main()
{
    add(5,6);
    add(8);
}