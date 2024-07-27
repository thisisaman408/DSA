#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string k;//we are using string, to get the whole binary number as input at once
    vector<int> v;
    cout << "Enter your binary number : ";
    cin >> k;
    for (char p : k)
    {
        v.push_back(p - '0');
    }
    int sum = 0;
    int x = 1;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        sum += v[i] * x;
        x *= 2;
    }
    cout << "The decimal value is : " << sum;
}
