#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        if (s.length() <= 2)
        {
            cout << "NO" << endl;
            continue;
        }
        if (s[0] == '1' and s[1] == '0' and s[2] != '0')
        {
            s = s.substr(2);
            int n = stoi(s);
            if (n > 2)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
