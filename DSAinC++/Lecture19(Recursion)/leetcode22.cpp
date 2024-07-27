#include <iostream>
#include <string>
using namespace std;
void generateParentheses(string s, int o, int c, int n)
{
    if (o == n && c == n)
    {
        cout << s;
        cout << endl;
        return;
    }
    if (o < n)
    {
        generateParentheses(s + "(", o + 1, c, n);
    }
    if (c < o && c < n)
    {
        generateParentheses(s + ")", o, c + 1, n);
    }
}

int main()
{
    int n;
    n = 3;
    string s = "";
    generateParentheses(s, 0, 0, n);
}