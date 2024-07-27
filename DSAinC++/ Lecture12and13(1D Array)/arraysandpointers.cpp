#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 4, 2, 5};
    int *ptr = arr; // stores address of arr[0]
    // int *ptr2 = &arr; // this is wrong and gives error as arr is already giving the address
    int *ptr2 = &arr[0]; // this is correct
    cout << ptr << endl
         << ptr2 << endl;
    for (int i = 0; i <= 3; i++)
    {
        cout << ptr[i] << endl;
        // with the help of pointer we can print our array
    }
    for (int i = 0; i <= 3; i++)
    {
        cout << ptr2[i] << endl;
        // with the help of pointer we can print our array
    }
    //in ptr2 there is address of first element which means aray of whole address
    //that's why behaving as the same as ptr 
    //basically [] is behavinga as *
}