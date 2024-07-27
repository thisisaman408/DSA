#include <iostream>
#include <vector>
using namespace std;

vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }
    for (int j = 0; j < queries.size(); j++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= queries[j])
            {
                count++;
            }
        }
        queries[j] = count;
    }
    return queries;
}
int main()
{
    vector<int> nums = {4, 5, 2, 1};
    vector<int> queries = {3, 10, 21};
    vector<int> ans = answerQueries(nums, queries);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}