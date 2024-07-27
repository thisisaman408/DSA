// to return total numbers in a digits without using any loop
#include <iostream>
using namespace std;
int main()
{
    int x;
    string s;
    cout << "Enter your number : " << endl;
    cin >> x;
    s = to_string(x);
    cout << s.size() << endl;
}