#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    int arr[] = {3, 5, 1, 7, -2, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }
    cout << pq.top() << endl;
}
// best with time complexity of