#include <iostream>
#include <vector>
/*
 Given N activities, along with their start[] and end[] day in an arrays, an activity can
 be performed by a person once a day, your task is to find the max activity a person can do,
 within the days
*/

// solution is just find the no of overlapping activities, and then subtract them from the total activites
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int maxAct(int N, vector<int> &start, vector<int> &end)
{
    vector<pair<int, int>> p;
    for (int i = 0; i < N; i++)
    {
        p.push_back({start[i], end[i]});
    }
    sort(p.begin(), p.end(), cmp);
    int count = 1; // atleast 1 activity can be performed always
    int lastEndtime = p[0].second;
    for (int i = 1; i < p.size(); i++)
    {
        if (p[i].first >= lastEndtime)
        {
            count++;
            lastEndtime = p[i].second;
        }
    }
    return count;
}
using namespace std;
int main()
{
    vector<int> start = {1, 2};
    vector<int> end = {2, 2};
    int N = 2;
    cout << maxAct(N, start, end);
}