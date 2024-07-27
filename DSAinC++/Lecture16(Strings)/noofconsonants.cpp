#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter your string : " << endl;
    getline(cin, s);
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    cout << count << endl;
}