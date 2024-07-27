#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canTransform(const string &s, const string &t)
{
    int n = s.size();
    int balance = 0;
    bool canTransform = true;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
            balance++;
        if (s[i] == '0')
            balance--;
        if (t[i] == '1')
            balance--;
        if (t[i] == '0')
            balance++;
        if (balance < 0)
        {
            canTransform = false;
            break;
        }
    }

    return canTransform;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        if (canTransform(s, t))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
