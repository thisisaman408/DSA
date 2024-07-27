#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int j = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
        if (pq.size() > k)
        {
            v[j++] = pq.top();
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        v[j++] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}