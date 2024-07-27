#include <iostream>
using namespace std;
void print()
{
    int b = 10;
    cout << b << endl;
    b++;
}
void static_print()
{
    static int b = 10;
    cout << b << endl;
    b++;
}
int main()
{

    print();
    print();
    print();

    // as you can see here, that whenver I call this print function, a new int block will be created,
    // there is no sense of incrementing the b  in the fucntion, cause whenever I call the print function, it just creates another variable

    static_print();
    static_print();
    static_print();
    // here as you can seee, that there is a change in the values, when we set the memmory of the variable as static, then it is the same old block
    //which was initialised as 10, doesn't matter anytime we call the function, no new creation of the int variable will happen
    //this maybe helpful in lots of cases, specially in oops as static data members
    
}