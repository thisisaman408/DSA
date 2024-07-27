#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pe = arr[(si + ei) / 2];
    int count = 0;
    for (int i = si; i <= ei; i++)
    {
        if (i == (si + ei) / 2)
            continue;
        if (arr[i] < pe)
        {
            count++;
        }
    }
    int pi = count + si;
    swap(arr[(si + ei) / 2], arr[pi]);
    int i = si;
    int j = ei;
    while (i < pi && j > pi)
    {
        if (arr[i] < arr[pi])
            i++;
        if (arr[j] > arr[pi])
            j--;
        if (arr[i] > pe && arr[j] <= pe)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pi;
}
int quickSort(int arr[], int si, int ei, int k)
{
    if (si >= ei)
        return 0;
    int pi = partition(arr, si, ei);
    if (k == (pi + 1))
        return arr[pi];
    if (k < (pi + 1))
    {
        quickSort(arr, si, pi - 1, k);
    }
    if (k > (pi + 1))
    {
        quickSort(arr, pi + 1, ei, k);
    }
    return arr[pi];
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {4, 6, 2, 5, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    printArray(arr, n);
    int p = quickSort(arr, 0, n - 1, k);
    printArray(arr, n);
    cout << p;
}