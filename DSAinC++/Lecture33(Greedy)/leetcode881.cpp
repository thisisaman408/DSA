#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int ans = 0;
        while (l <= r)
        {
            if (people[l] + people[r] <= limit)
                l++;
            r--;
            ans++;
        }
        return ans;
    }
};
int main()
{
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    Solution ans;

    cout << ans.numRescueBoats(people, limit);

    return 0;
}
