/*
bubble sort is basically a sorting technique, in which we sort a array in ascending order (geneerally)
we basically compare an element say a to it's next element say b, if a > b, then swap a and b and so on
*/
#include <iostream>
using namespace std;

void swap(int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}
// function for bubble sort (optimised)
void bubblesort(int n, int arr[])
{
    // n -1 because, we will not compare last element to any other element (cause next element to last element do not exist, so no comparision of n -1th element)
    for (int i = 0; i < n - 1; i++)
    {
        /*
        this flag is used, to even further optimise the code, say if we have  5 1 2 3 4, for  this, the array is sorted after 1st pass
        but still, the ith loop will run n - 1 or here 4 times, which is useless, so we will check if there is no swapping in j loop in one pass
        that means, the array is aleady sorted, so when there is no swapping we will make flag false, and if, after the one complete pass of j loop, flag = true,
        so we will know that iteration did not go inside if condition (if it had been gone then flag would become false)
        so that's how we will break the loop
        */
        bool flag = true;
        /*
        here n - i - 1, because, after first pass, there will be 1 element which is sorted, if we use just
        n - 1, then, in second pass, this loop will again compare that sorted element (in 1st pass), with it's next element (which do not exist),
        similarly for 2nd pass, there will be 2 sorted elements, so we will have to run j loop 2 less times, for 3rd pass, 3 less times, for ith pass, i less times, to save iterations*/
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
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
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubblesort(n, arr);
    cout << "Sorted array  : ";
    printarray(n, arr);
    return 0;
}
// time complexity of bubble sort is O(n^2)
// bubble sort is stable sorting, which means if there is 1 2( green) 2 (black) 6 3
// so the output of the bubble sort will be 1 2 (green) 2(black) 3 6, it will maintain the order of the same elements this property is called stable
// no of passes = n - 1 (ith looop is used to calculate of passses)
// no of swaps = n (n - 1)/2 (jth loop is used)