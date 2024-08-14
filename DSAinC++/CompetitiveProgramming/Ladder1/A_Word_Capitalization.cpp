#include <iostream>
using namespace std;

int main()
{

    char s;
    bool flag = true;
    while (cin >> s)
    {
        if (flag)
        {
            if (s >= 'a' and s <= 'z')  s = s - 32;
            flag = false;
            cout << s;
        }
        else cout << s;
    }
}