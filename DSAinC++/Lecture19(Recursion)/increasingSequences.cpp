#include <iostream>
#include <string>
#include <vector>
using namespace std;

void increaseSequence(vector<int> &original, vector<int> ans, int idx, int k)
{
    if (idx == original.size())
    {
        if (ans.size() == k)
        {
            for (int i = 0; i < ans.size(); ++i)
            {
                cout << ans[i];
            }
            cout << endl;
        }
        return;
    }
    if (ans.size() + (original.size() - idx) < k)
    {
        return;
    }
    increaseSequence(original, ans, idx + 1, k);
    ans.push_back(original[idx]);
    increaseSequence(original, ans, idx + 1, k);
}
int main()
{
    vector<int> original = {1, 2, 3};
    vector<int> v;
    int k = 2;
    increaseSequence(original, v, 0, k);
}
