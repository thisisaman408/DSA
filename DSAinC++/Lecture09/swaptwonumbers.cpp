#include <iostream>
using namespace std;
void swap(int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;
    cout << x << " " << y;
}
int main()
{
    swap(4, 5);
}