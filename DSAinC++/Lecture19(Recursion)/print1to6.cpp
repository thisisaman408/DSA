#include <iostream>
using namespace std;
void print(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    print(i + 1, n);
}
int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    print(1, n);
}
//here to use recursion, we have to use an extra parameter,