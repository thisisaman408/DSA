#include <iostream>
using namespace std;
void removeChar(string ans, string s, int idx)
{

    if (idx == s.size())
    {
        cout << ans<<" ";
        return;
    }
    if (s[idx] == 'a')
        removeChar(ans, s, idx + 1);
    else
        removeChar(ans + s[idx], s, idx + 1);
}
int main()
{
    string s = "aabscaads";
    removeChar("", s, 0);
}