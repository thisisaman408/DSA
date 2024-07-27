#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pivotELe = arr[(si + ei) / 2];
    int i = si - 1;
    int j = ei + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivotELe);

        do
        {
            j--;
        } while (arr[j] > pivotELe);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int si, int ei)
{
    if (si >= ei)
        return;
    int pi = partition(arr, si, ei);
    quickSort(arr, si, pi - 1);
    quickSort(arr, pi + 1, ei);
}
int find_unique(int arr[], int n)
{
    sort(arr, arr + n);
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if (arr[i] == arr[j])
        {
            i += 2;
            j += 2;
        }
        else
            break;
    }
    return arr[i];
}

int find_unique_better(int arr[], int n)
{
    int reus = 0;
    for (int i= 0; i< n; i++){
        reus ^= arr[i];
    }
    return reus;
}
int main()
{
    int p[] = {2, 1, 3, 2, 1, 5, 5, 6, 3};
    cout << find_unique(p, 9) << endl;
    cout << find_unique_better(p, 9);
}