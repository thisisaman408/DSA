#include <iostream>
using namespace std;
int main()
{
    int arr[9];
    int n;
    cout << "Enter the elements for the array" << endl;
    for (int i = 0; i <= 8; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the value of number you want to search in array : " << endl;
    cin >> n;
    for (int i = 0; i <= 8; i++)
    {
        if (n == arr[i])
        {
            cout << i;
        }
    }
}