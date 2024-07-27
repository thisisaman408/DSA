#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countVowelPermutation(int n)
    {
        const int MOD = 1000000007;

        vector<long long> prev(5, 1);

        for (int i = 2; i <= n; ++i)
        {
            vector<long long> curr(5, 0);

            curr[0] = (prev[1] + prev[2] + prev[4]) % MOD;
            curr[1] = (prev[0] + prev[2]) % MOD;
            curr[2] = (prev[1] + prev[3]) % MOD;
            curr[3] = (prev[2]) % MOD;
            curr[4] = (prev[2] + prev[3]) % MOD;

            prev = curr;
        }

        long long totalCount = 0;
        for (int j = 0; j < 5; ++j)
        {
            totalCount = (totalCount + prev[j]) % MOD;
        }

        return totalCount;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << "Result for n = " << n << ": " << sol.countVowelPermutation(n) << endl;
    return 0;
}
