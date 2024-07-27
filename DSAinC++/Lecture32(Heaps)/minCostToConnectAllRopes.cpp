#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {2, 7, 4, 1, 8};
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int ele : v)
    {
        pq.push(ele);
    }

    int sum = 0;
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x + y);
        sum += x + y;
    }

    cout << sum << endl;
}
