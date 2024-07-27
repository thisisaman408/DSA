#include <iostream>
using namespace std;
int atob(int a, int b)
{
    if (b == 0){
        return 1;
    }
    int p = a * atob(a, b - 1);
    return p;
}
int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    int p = atob(a, b);
    cout <<p;
}