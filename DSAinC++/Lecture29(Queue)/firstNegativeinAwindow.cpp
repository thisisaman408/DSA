#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {3, -4, -7, 30, 7, -9, 2, 1, 6, -1};
    //-4 -4 -7 -9 -9 - 9 0 -1 this should be our answer
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Window size
    vector<int> ans;
    queue<int> q;

    // Initialize the queue with the indices of negative numbers within the first window
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }

    int i = 0;
    // Process the rest of the array
    while (i <= n - k)
    {
        // Remove elements that are out of the current window
        while (!q.empty() && q.front() < i)
        {
            q.pop();
        }

        // Add the first negative number of the current window to the result
        if (q.empty() || q.front() >= i + k)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[q.front()]); // If there's no negative number in the current window
        }
        i++;
    }
    // Print the result
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
