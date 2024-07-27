#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void helper(vector<int> &nums, vector<int> ans, vector<vector<int>> &finalAns, int index)
    {
        finalAns.push_back(ans); // Include the current subset

        for (int i = index; i < nums.size(); ++i)
        {
            if (i == index || nums[i] != nums[i - 1])
            {                                       // Skip duplicates
                ans.push_back(nums[i]);             // Include the current element
                helper(nums, ans, finalAns, i + 1); // Recur with the next index
                ans.pop_back();                     // Backtrack
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates
        vector<int> ans;
        vector<vector<int>> finalAns;
        helper(nums, ans, finalAns, 0);
        return finalAns;
    }
};

int main()
{
    Solution solution;

    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> result = solution.subsetsWithDup(v);

    cout << "Subsets with duplicates: " << endl;
    for (const auto &subset : result)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            if (subset.size() == 1 || i == subset.size() - 1)
            {
                cout << subset[i];
            }
            else
            {
                cout << subset[i] << ",";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
