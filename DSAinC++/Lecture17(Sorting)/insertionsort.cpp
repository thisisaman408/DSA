/*
insertion sort, is for example, 3 4 5 1 2, we will divide this array in two parts
3  4 5 1 2 , so first 4 will go in first part, and it will get place to the right of 3
as 3 4     5 1 2 , here comes 5, 3 4 5    1 2 , now 1, we will compare 1 to the other elements
of the first part of the array, so 1 3 4 5    2 , similarly 2, 1 2 3 4 5, this is insertion sort
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;
void swap(int *m, int *n)
{

    int temp = *m;
    *m = *n;
    *n = temp;
}

void insertionsort(int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            swap(arr[j], arr[j - 1]);
        }
    }
}
void printarray(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionsort(n, arr);
    printarray(n, arr);
}
/*
time complexity
worst case : O(n^2)
average case : O(n^2)
best case : O(n)

in average case the inner loop won't run
best CASE is 1 2 3 4

insertion sort is stable algorithm
*/