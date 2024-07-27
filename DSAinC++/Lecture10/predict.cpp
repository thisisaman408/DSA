#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int *p = &a;
    int b = ++(*p); // here first value at pointer p is incremented. thus
    // a is incremented thus a becomes 6, now this value is stored in b
    cout << a << " " << b; // here we will get our output as 6 6.
}

// now if in line 7 we write it int b = (*p)++;
//so here it means that first assign the value of stored at address p to b
//then increment p, thus in this case , there should be output as 6 5, 
//thus a becomes 6 and b becomes 5