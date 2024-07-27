/*
in selection sort, we have to find the minimum element in the array, and then we swap this element with the first element
of the array, and this process goes on
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
void swap(int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}
void selectionsort(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        int minidx = -1;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minidx = j; // we need index of minimum element
            }
        }
        swap(arr[i], arr[minidx]);
    }
}
void printarray(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout << ele << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> arr;
    int x;
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    selectionsort(n, arr);
    printarray(arr);
}

// for each loop
/*
for (int ele : arr){
cout <<ele;
this will print the whole array, basically it is used to print all the elements of the array, wihtout any condition
}
*/
/*
time complexity of selection sort
worst case : O(n^2), best case or average case
space complexity is same asO(1);
uses ?
can be used when only first k minimun numbers are asked, 
can be used when no of swaps should be minimum

*/