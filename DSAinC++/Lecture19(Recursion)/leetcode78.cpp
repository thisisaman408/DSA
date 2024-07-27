#include <iostream>
#include <vector>
using namespace std;

void storeSubset(vector<int> &nums, vector<int> ans, vector<vector<int>> &finalAns, int idx)
{
    if (idx == nums.size())
    {
        finalAns.push_back(ans);
        return;
    }
    storeSubset(nums, ans, finalAns, idx + 1);
    ans.push_back(nums[idx]);
    storeSubset(nums, ans, finalAns, idx + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    vector<vector<int>> finalAns;
    storeSubset(nums, ans, finalAns, 0);
    for (int i = 0; i < finalAns.size(); i++)
    {
        for (int j = 0; j < finalAns[i].size(); j++) // Correct loop condition
        {
            cout << finalAns[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
