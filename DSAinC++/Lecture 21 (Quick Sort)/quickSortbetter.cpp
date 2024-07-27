#include <iostream>
using namespace std;
int partition(int arr[], int si, int ei)
{
    int pivotELe = arr[(si + ei) / 2];
    // this one has better tc, always gonna be O(n log n)
    int count = 0;
    for (int i = si; i <= ei; i++)
    {
        if (i == (si + ei) / 2)
            continue;
        if (arr[i] < pivotELe)
            count++;
    }
    int pivotIdx = count + si;
    swap(arr[(si + ei) / 2], arr[pivotIdx]);
    int i = si;
    int j = ei;
    while (i < pivotIdx && j > pivotIdx)
    {
        if (arr[i] <= pivotELe)
            i++;
        if (arr[j] > pivotELe)
            j--;
        else if (arr[i] > pivotELe && arr[j] <= pivotELe)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}
void quickSort(int arr[], int si, int ei)
{
    if (si >= ei)
        return;
    int pi = partition(arr, si, ei);
    quickSort(arr, si, pi - 1);
    quickSort(arr, pi + 1, ei);
}
int main()
{

    int arr[] = {5, 1, 8, 2, 7, 6, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    quickSort(arr, 0, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}