#include <iostream>
#include <string>
using namespace std;

void permutation(string ans, string original)
{
    int n = original.size();
    if (original == "")
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        char ch = original[i];
        string rest = original.substr(0, i) + original.substr(i + 1);
        permutation(ans + ch, rest);
    }
}

int main()
{
    string s = "123";
    string ans = "";
    permutation(ans, s);
    return 0;
}
