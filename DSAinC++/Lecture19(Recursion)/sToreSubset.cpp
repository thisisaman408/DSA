#include <iostream>
#include <string>
#include <vector>
using namespace std;

void storeSubset(string ans, string original, vector<string> &v)
{
    if (original == "")
    {
        v.push_back(ans);
        return;
    }
    char ch = original[0];

    storeSubset(ans, original.substr(1), v);
    storeSubset(ans + ch, original.substr(1), v);
}
int main()
{
    string s = "abc";
    vector<string> v;
    storeSubset("", s, v);
    for (string e : v)
    {
        cout << e << endl;
    }
}
//here we are storing all those subsets in a vector named v