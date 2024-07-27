#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size of your array : " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array : " << endl;
    for (int i = 0; i <= size - 1; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 1; i <= size - 1; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int min = arr[0];
    for (int i = 1; i <= size - 1; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    int smax = arr[0];
    for (int i = 0; i <= size - 1; i++)
    {
        if (arr[i] > smax && arr[i] != max)
        {
            smax = arr[i];
        }
    }
    int smin = arr[0];
    for (int i = 0; i <= size - 1; i++)
    {
        if (arr[i] < smin && arr[i] != min)
        {
            smin = arr[i];
        }
    }
    cout << "Greatest Element : " << max << endl;
    cout << "Second Greatest Element : " << smax << endl;
    cout << "Lowest Element : " << min << endl;
    cout << "Second Lowest Element : " << smin << endl;
}