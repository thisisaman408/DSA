#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    int a = (p1.first) / (p1.second);
    int b = (p2.first) / (p2.second);
    return a > b;
}
double knapsack(vector<int> &profit, vector<int> &weights, int n, int W)
{
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        p.push_back({profit[i], weights[i]});
    }
    sort(p.begin(), p.end(), cmp);
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].second < W)
        {
            result += p[i].first;
            W -= p[i].second;
        }
        else
        {
            result += (p[i].first) / (p[i].second) * W;
            break;
        }
    }
    return result;
}
int main()
{
    vector<int> profit = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int n = 3;
    int W = 50;
    cout << knapsack(profit, weights, n, W);

    return 0;
}