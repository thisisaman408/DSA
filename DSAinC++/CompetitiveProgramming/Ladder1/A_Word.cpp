#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int capCount = 0;
    int smallCount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z') capCount++;
        else if ('a' <= s[i] && s[i] <= 'z') smallCount++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (smallCount < capCount)
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                s[i] = s[i] - 32;
            }
        }
        else
        {
            if ('A' <= s[i] && s[i] <= 'Z')
            {
                s[i] = s[i] + 32;
            }
        }
    }

    cout << s << endl;
    return 0;
}
