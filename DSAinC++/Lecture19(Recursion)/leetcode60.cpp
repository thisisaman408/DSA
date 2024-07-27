#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permutation(vector<string> ans, string original)
{
    int n = original.size();
    if (original == "")
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        char ch = original[i];
        string rest = original.substr(0, i) + original.substr(i + 1);
       
        permutation(ans, rest);
    }
}

int main()
{
    string s = "123";
    vector<string> ans;
    permutation(ans, s);
    return 0;
}
