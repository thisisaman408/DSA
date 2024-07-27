#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

int main()
{
    int a,b;
    int *x = &a;//it is important to initialise a pointer to avoid bus error
    int *y = &b;
    cin >> *x;
    cin >> *y;
    swap(x, y);
    cout << *x << *y;
}