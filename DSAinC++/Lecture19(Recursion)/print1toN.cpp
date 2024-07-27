// without an extra parameter
#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    print(n - 1);//recursive call ke baad, print kara hai bss, else code n to 1 wla hi hai
    cout << n << endl;
}
int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    print(n);
}
