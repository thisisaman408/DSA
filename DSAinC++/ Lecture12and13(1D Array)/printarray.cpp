#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr; // stores address
    // now we will print all the elements without using []
    for (int i = 0; i <= 4; i++)
    {
        cout << *ptr << " ";
        ;
        ptr++;
    }
    cout << endl;
    // now after this loop this ptr is lost, it is no longer pointing
    // to the first element of the array
    ptr = arr; // now it is again pointing the first element of the array
    *ptr = 8;  // pointer is at first element so arr[0]= 8;
    ptr++;     // pointer is at second element
    *ptr = 9;  // arr[1]= 9;
    ptr--;     // again pointer is at first element thus it is not lost
    for (int i = 0; i <= 4; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }
    ptr = arr; // again to point it to the first element of array
    // we know that when we do ptr++ and ptr is a pointer
    // then it gets incremented by the value of the size of data type
}
// here we can also array as i[arr] or i[ptr] in place cout <<*ptr;