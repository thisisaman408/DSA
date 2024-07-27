#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "Enter your string" << endl;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 != 0)
        {
            s[i] = '#';
        }
    }
    cout << s << endl;
}