/*
Q3 You are given a non-negative integer array nums. In one operation, you must:
Choose a positive integer x such that x is less than or equal to the smallest non-zero element
in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minOperationsToZero(vector<int> &nums)
{
    // Sort the vector
    sort(nums.begin(), nums.end());
    // 0 1 3 5 5

    int count = 0; // Count of unique positive values
    int prev = 0;  // Previous value in the sorted vector

    for (int num : nums)
    {
        // We count this number only if it's a positive number and greater than the previous number
        if (num > 0 && num != prev)
        {
            count++;
            prev = num; // Update previous number to the current one
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 5, 0, 3, 5};
    cout << "Minimum number of operations: " << minOperationsToZero(nums) << endl;
    return 0;
}
