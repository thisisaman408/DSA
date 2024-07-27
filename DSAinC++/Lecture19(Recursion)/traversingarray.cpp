#include <iostream>
using namespace std;
void display(int n, int arr[], int idx)
{
    if(idx == n) return;
    cout<<arr[idx]<<" ";
    display(n,arr,idx+1);
}
int main()
{
    int n;
    int arr[] = {3, 4, 2, 5, 2, 4, 2, 12, 32, 32, 21};
    n = sizeof(arr) / sizeof(arr[0]);
    display(n,arr,0);
}