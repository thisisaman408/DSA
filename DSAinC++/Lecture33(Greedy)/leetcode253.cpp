/*
Problem: Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],…] (si < ei), find the minimum number of conference rooms required.

Example(s):

For example, Given [[0, 30],[5, 10],[15, 20]], return 2.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int meetingRooms(vector<vector<int>> &rooms)
    {
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < rooms.size(); i++)
        {
            start.push_back(rooms[i][0]);
            end.push_back(rooms[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int room = 0;
        int ans = 0;
        int i = 0;
        int j = 0;

        while (i < start.size() && j < end.size())
        {
            if (start[i] == end[i])
            {
                i++;
                j++;
            }
            else if (start[i] < end[j])
            {
                room++;
                ans = max(ans, room);
                i++;
            }
            else
            {
                room--;
                j++;
            }
        }

        return ans;
    }

private:
    void print(vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    vector<vector<int>> rooms = {{0, 30}, {5, 10}, {15, 20}};
    Solution sol;
    cout << sol.meetingRooms(rooms);
}