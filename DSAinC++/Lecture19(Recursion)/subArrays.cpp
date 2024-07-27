#include <iostream>
#include <vector>
using namespace std;
void subArray(vector<int> ans, vector<int> v, int index)
{
    if (index == v.size())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        cout << endl;
        return;
    }

    subArray(ans, v, index + 1);
    if (ans.size() == 0 || (ans[ans.size() - 1] == v[index - 1]))
    {
        ans.push_back(v[index]);
        subArray(ans, v, index + 1);
    }
}
int main()
{
    vector<int> v = {1, 2, 3, 4};
    vector<int> ans;
    subArray(ans, v, 0);
}
// dry run this code, with recursion tree by drawing it in notebook, you will see, that
//we have to modify the conditions when to call the second function