#include <iostream>
#include <vector>
using namespace std;
void combinationSum(vector<int> ans, vector<int> &original, int target, int idx)
{
    if (target == 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    if (target < 0)
    {
        return;
    }
    //if right now i = 2, so next time i will not call 1 or 0, or any no lesser than 2 
    //to avoid repitition
    for (int i = idx; i < original.size(); i++)
    {
        ans.push_back(original[i]);
        combinationSum(ans, original, target - original[i], i);
        ans.pop_back();
    }
}
using namespace std;
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    int target = 3;
    combinationSum(ans, nums, target, 0);
}
// we can remove the repitition, by passing an index to the function