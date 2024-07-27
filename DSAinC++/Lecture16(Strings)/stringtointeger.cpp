#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout << "Enter your string " << endl;
    string s;
    getline(cin, s);
    int len = s.size();
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = s[i] - '0';// ASCII value of 0 is 48, so if I write 1,so output will be 49,
        //as the ASCII value of 1 is 49, so we minus the '0'
    }
    for (int i = 0; i < len; i++)
    {
        cout << arr[i];
    }
}