#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int arr[] = {3, 5, 1, 7, -2, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    // i have to find the 4th largest element of this array
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int k = 4; // 4th largest element
    for (int i = 1; i < k; i++)
    {
        pq.pop();
    }
    cout << pq.top(); // working perfectly
    
}