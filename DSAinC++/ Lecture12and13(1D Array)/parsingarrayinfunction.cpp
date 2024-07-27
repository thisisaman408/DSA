#include <iostream>
using namespace std;
void display(int a[])// we can also write int* a[], still code remains same
{//here if we use int size = sizeof(a)/sizeof(a[0]),so
//this will give us a warning, because actually here this a
//is a pointer pointing towards the first element of array that's why
//we are able to modify the values of array.
    for (int i = 0; i <= 4; i++)
    {
        cout << a[i] << endl;
    }
}
void change(int b[])//also int* b
{
    b[0] = 100;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    display(arr);
    change(arr);
    display(arr);
}
// the thing we need to be under consideration is that
//when we were passing integer etc without pointers so it was
//pass by values, if we want to do pass by reference, which means
//to change in values of variables we have to pass address of variable
//so compiler will go to that address and will change it, in function the variable
//we declare are different and the variables we declare inside our main function
//are different, so if we pass any value in function from any function so the change
//shall be in different variable, so we could not access them, but when we pass address
//and receive address on the function, now on a particular address there shall be a particular variable
//so by this logic we pass actually the same variable into the function, this is called pass by reference
//now, the same happens in the case of arrays, but the best thing is we do not need to decalre the array pointer
//to access it in other function as call by reference it is default.
//so when we pass an array to a function it is call by reference and not call by value.
