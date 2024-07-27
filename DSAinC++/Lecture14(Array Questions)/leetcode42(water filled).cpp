#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    int pge[n];
    int nge[n];
    pge[0] = -1;
    int max = height[0];
    // previous greatest element
    for (int i = 1; i < n; i++)
    {
        pge[i] = max;
        if (max < height[i])
        {
            max = height[i];
        }
    }
    nge[n - 1] = -1;
    max = height[n - 1];
    // next greatest element
    for (int i = n - 2; i >= 0; i--)
    {
        nge[i] = max;
        if (max < height[i])
        {
            max = height[i];
        }
    }
    // minimum of nge and pge in pge
    for (int i = 1; i < n - 1; i++)
    {
        pge[i] = min(pge[i], nge[i]);
    }
    int water = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (height[i] < pge[i])
        {
            water += pge[i] - height[i];
        }
    }
    return water;
}
int main()
{
    vector<int> height;
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter your elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        height.push_back(x);
    }
    int water = trap(height);
    cout << "The portion into which water shall be trapped is : " << water << endl;
}