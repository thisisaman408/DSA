#include <iostream>
using namespace std;
int main()
{
    int p = 5;
    int q = 10;
    p += q -= p;
    cout << p << " " << q << endl;
    return 0;
}
// here the precedence of = operator is from right to left, so q -= p is evaluated first