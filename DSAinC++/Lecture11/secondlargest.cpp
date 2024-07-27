#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of your array: " << endl;
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid array size. Exiting." << endl;
        return 1; // Exit the program with an error code
    }

    int arr[size];

    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int max = arr[0];
    int smax = INT_MIN;

    for (int i = 1; i < size; i++)
    { // Start from index 1
        if (arr[i] > max)
        {
            smax = max; // Update smax before max
            max = arr[i];
        }
        else if (arr[i] != max && arr[i] > smax)
        {
            smax = arr[i];
        }
    }

    if (smax != INT_MIN)
    {
        cout << "Maximum: " << max << endl;
        cout << "Second Maximum: " << smax << endl;
    }
    else
    {
        cout << "There is no second maximum." << endl;
    }

    return 0;
}
