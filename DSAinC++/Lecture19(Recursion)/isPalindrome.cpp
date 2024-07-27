#include <iostream>
using namespace std;
bool palindrome(string &s, int i, int j)
{
    if (s[i] == s[j])
    {
        return true;
    }
    else
    {
        return false;
    }
    palindrome(s, i++, j--);
}
int main()
{
    string s;
    cout << "Enter your string : ";
    getline(cin, s);
    cout << palindrome(s, 0, s.size() - 1);
}