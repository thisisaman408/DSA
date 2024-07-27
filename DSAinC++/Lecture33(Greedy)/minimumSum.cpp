/*
    Given two arrays a[] and b[] of the same size. Task is to find the minimum sum of two
elements such that they belong to different arrays and are not at the same index in their
arrays.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

// Function to find the minimum sum of two elements where one comes from array a
// and the other comes from array b, ensuring they are not at the same index.
typedef pair<int, int> pi; // Pair to store (value, index)

int findMinSumUsingHeaps(const vector<int> &a, const vector<int> &b)
{
    int n = a.size();

    // Create min-heaps for array a and array b
    priority_queue<pi, vector<pi>, greater<pi>> heap_a;
    priority_queue<pi, vector<pi>, greater<pi>> heap_b;

    // Populate heaps
    for (int i = 0; i < n; ++i)
    {
        heap_a.push({a[i], i});
        heap_b.push({b[i], i});
    }

    // Extract the smallest elements from both heaps
    pi min_a = heap_a.top();
    pi min_b = heap_b.top();
    heap_a.pop();
    heap_b.pop();

    int min_sum = INT_MAX;

    // If the smallest elements come from different indices, return their sum
    if (min_a.second != min_b.second)
    {
        min_sum = min_a.first + min_b.first;
    }
    else
    {
        // We need to check the second smallest elements as well
        pi second_min_a = heap_a.top();
        pi second_min_b = heap_b.top();

        // Compute possible minimum sums with the second smallest elements
        int sum_with_second_min_a = second_min_a.first + min_b.first;
        int sum_with_second_min_b = min_a.first + second_min_b.first;

        min_sum = min({min_sum, sum_with_second_min_a, sum_with_second_min_b});
    }

    return min_sum;
}

int main()
{
    vector<int> a = {5, 4, 13, 1};
    vector<int> b = {3, 2, 6, 1};

    int result = findMinSumUsingHeaps(a, b);

    cout << "Minimum sum is: " << result << endl;

    return 0;
}