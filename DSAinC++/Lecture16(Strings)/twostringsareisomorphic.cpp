/*
check if two given strings are isomorphic or not
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s;
    string t;
    cout << "Enter first string : " << endl;
    cin >> s;
    cout << "Enter second string : " << endl;
    cin >> t;
    vector<int> v(150, 1000);
    if (s.size() != t.size())
    {
        cout << "false" << endl;
    }
    bool b = true;

    for (int i = 0; i < s.size(); i++)
    {
        int idx = (int)s[i];
        if (v[idx] == 1000)
        {
            v[idx] = s[i] - t[i];
        }
        else if (v[idx] != (s[i] - t[i]))
        {
            b = false;
            cout << b << endl;
        }
    }
    for (int i = 0; i < 150; i++)
    {
        v[i] = 1000;
    }
    for (int i = 0; i < s.size(); i++)
    {
        int idx = (int)t[i];
        if (v[idx] == 1000)
        {
            v[idx] = t[i] - s[i];
        }
        else if (v[idx] != (t[i] - s[i]))
        {
            b = false;
            cout << b << endl;
        }
    }

    if (b != false)
        cout << "true" << endl;

}
