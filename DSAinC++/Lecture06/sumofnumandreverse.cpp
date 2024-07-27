#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter your number : " << endl;
    cin >> n;
    int reverse = 0;
    int a = n;
    int b = n;
    while (n != 0)
    {
        a = n % 10;
        reverse *= 10;
        reverse = reverse + a;
        n /= 10;
    }
    cout <<"The reverse value is : " << reverse <<endl;
    cout<<"The sum of number and it's reverse is "<< (reverse + b)<<endl;
}