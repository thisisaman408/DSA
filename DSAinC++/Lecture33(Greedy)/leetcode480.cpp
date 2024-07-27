/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation:
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
Example 2:

Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]


Constraints:

1 <= k <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    void print(multiset<double> &ms)
    {
        for (multiset<double>::iterator it = ms.begin(); it != ms.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> ans;
        // 1, 3, -1, -3, 5, 3, 6, 7
        multiset<double> window(nums.begin(), nums.begin() + k);
        print(window);
        auto it = next(window.begin(), (k - 1) / 2);

        for (int i = k;; ++i)
        {
            const double median = k & 1 ? *it : (*it + *next(it)) / 2.0;
            cout << median << endl;
            ans.push_back(median);
            if (i == nums.size())
                break;
            window.insert(nums[i]);
            print(window);
            if (nums[i] < *it)
                --it;
            if (nums[i - k] <= *it)
                ++it;
            cout << i << " " << k << endl;
            cout << nums[i - k] << endl;
            window.erase(window.lower_bound(nums[i - k]));
            print(window);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<double> ans = sol.medianSlidingWindow(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}