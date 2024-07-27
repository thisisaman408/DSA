#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size of your array : " << endl;
    cin >> size;
    int arr[size];
    int n;
    cout << "Enter the elements of array : " << endl;
    for (int i = 0; i <= size - 1; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 0; i <= size - 1; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max;
}