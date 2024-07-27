/*
leetcode 169
we have to find the number which is occuring more than n/2 in an array,
if we sort the array, then
if array size is 100, say
then n/2 = 50, thus element which occurs more than 50 times,
doesn't matter where the element is, if it is sorted it must be together,
and it must be at n/2 index
*/
#include <iostream>
#include <vector>
using namespace std;
int maximum(int n, vector<int> &v)
{
    sort(v.begin(), v.end());
    return v[n / 2];
}

int main()
{
    int n;
    cout << "Enter the size of vector : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int a = maximum(n, v);
    cout << a;
}
