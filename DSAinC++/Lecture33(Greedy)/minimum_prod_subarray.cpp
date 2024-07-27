#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int minProduct(vector<int> &arr)
{
    int nneg = 0; // Number of negative numbers
    int nz = 0;   // Number of zeros
    int np = 0;   // Number of positive numbers
    int prod_neg = 1;
    int prod_pos = 1;
    int max_neg = INT_MIN;
    int min_pos = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            nneg++;
            prod_neg *= arr[i];
            max_neg = max(max_neg, arr[i]);
        }
        else if (arr[i] == 0)
        {
            nz++;
        }
        else
        {
            np++;
            prod_pos *= arr[i];
            min_pos = min(min_pos, arr[i]);
        }
    }

    if (nneg == 0)
    {
        // No negative numbers
        if (nz > 0)
        {
            return 0; // If there's any zero, return 0
        }
        else
        {
            return min_pos; // Otherwise return the smallest positive number
        }
    }
    else
    {
        // Negative numbers do exist
        if (nneg % 2 == 0)
        {
            // Even number of negative numbers, remove the largest negative number
            prod_neg /= max_neg;
        }
        // Return the product of all negatives and positives
        return prod_neg * prod_pos;
    }
}

int main()
{
    vector<int> arr = {-1, -2, -3, 4, 5};
    cout << minProduct(arr) << endl; // Output should be the minimum product
    return 0;
}
