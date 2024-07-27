// input a string, and find the no of times the characters are different from each other
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "Enter your string" << endl;
    getline(cin, s);
    int len = s.size();
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (len == 1)
        {
            cout << 0;
        }
        else if (len == 2)
        {
            cout << 1;
        }
        else
        {
            if (s[i] != s[i + 1] && s[i] != s[i - 1])
            {
                count++;
            }
        }
    }
    cout << count << endl;
}

// string abbbcccdde
/*
here,
j = 0; and i = 1;
s[0] = s[j] : s[1] = s[0], No
so, i = i + 2; thus i = 3, j = 1;

*/