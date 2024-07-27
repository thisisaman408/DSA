#include <iostream>
using namespace std;
int main()
{
    int x = 4;
    int *p = &x;
    cout << p << endl;
    p++;
    cout << p;
}
/*HEre the thing we learnt is that, the address is stored in hexadecimal values
which is 0 1 2 3 4 5 6 7 8 9 a b c d e f , these are hexadecimal numbers.
Now, as we initialise int* p as integera pointer, so when we increment it, so the address 
stored in pointer get incremented, but here as it is integer type and a int variable 
uses 4 byte of memory, so address will get incremented by 4 byted and not 1 byte*/