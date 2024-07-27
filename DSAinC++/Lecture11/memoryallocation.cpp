#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3};
    cout << arr << endl;//similar as cout <<&arr;
    cout << &arr << endl;
    cout << &arr[0] << endl;
    cout << &arr[1] << endl;
    cout << &arr[2] << endl;
}
// here we can see firsr, address of array is same as the address of first element
// of array, also elements are stored in continous memory allocation, as these are
// integer type, so there is gap of 4 bytes between each element, also address of
// single variable is the address of first byte

// IMPORTANT: in C++, cout <<arr; also gives address of array or address of first element
// of array