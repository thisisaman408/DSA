/*
    You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.



Example 1:

Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
Example 2:

Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa".
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
*/

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    typedef pair<char, int> pi;
    string repeatLimitedString(string &s, int &repeatLimit)
    {
        unordered_map<char, int> mp;
        for (char ele : s)
        {
            mp[ele]++;
        }
        priority_queue<pi> pq;
        for (auto &x : mp)
        {
            pq.push(x);
        }
        string ans;
        while (!pq.empty())
        {
            int let = pq.top().first;
            int occ = pq.top().second;
            pq.pop();

            int use = min(repeatLimit, occ);
            ans.append(use, let);
            occ -= use;
            if (occ > 0)
            {
                if (pq.empty())
                    break;
                int nextlet = pq.top().first;
                int nextOcc = pq.top().second;
                pq.pop();
                ans += nextlet;
                nextOcc--;
                if (nextOcc > 0)
                    pq.push({nextlet, nextOcc});
                pq.push({let, occ});
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "cczazcc";
    int repeatLimit = 3;
    cout << sol.repeatLimitedString(s, repeatLimit);
    return 0;
}
