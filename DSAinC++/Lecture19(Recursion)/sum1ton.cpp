#include <iostream>
using namespace std;
void sum(int sun, int n)
{
    if( n == 0) {
        cout <<sun<<endl;
        return;
    }
    sum (sun + n, n - 1);
}
int main()
{
    int n;
    cin>>n;
    sum(0,n);
}