/*Here, we have to take input as integers and then print
half of that  number, even of decimal numbers, so
basically we'll typecast int to float*/

#include <iostream>
using namespace std;
int main()
{
    int x;
    cout <<"Enter your number : " << endl;
    cin >> x;
    cout << ((float)x / 2);
    return 0;
}
/*
we are typecasting to float just because, the half of 5 is 2.5, so that we can
print 2.5*/