#include <iostream>
using namespace std;
void find_unique(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res ^= arr[i];
    }
    int temp = res;
    int k = 0;
    while (1)
    {
        if ((temp & 1) == 1)
            break;
        temp = temp >> k;
        k++;
    }
    int retvalue = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        if (((num >> k) & 1) == 1)
            retvalue ^= num;
    }
    cout << retvalue << " ";
    res ^= retvalue;
    cout << res << " ";
}

int main()
{
    int arr[] = {1, 2, 1, 3, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    find_unique(arr, size);
}
// here every element is being repeated twice, but only two numbers are repeated once, we have to return those two numbers
/*
So, we basicallly, first took xor of every elemnent of  our array, here we get at the end 3 ^ 5 as (x ^ x == 0)
now, 3 ^ 5 is 6, we check that it has it's first set bit at 1 element, we call it  k generally, now
what does this mean, if it has set bit at 1, and we know that, if after xor operation we are getting it means, that those two 
bits in the operation must be different, so one of the number in operation  must have set bit at the same place as in 6, 
so now we will check the other elements of the array, and we will check if any of the number have set bit at kth position or in this case at 1 position,
so after searching we get here 3, as 011,it has a set bit at 1 position, so we will do it's xor with 0, and this is also one of our answer
now, we can simply get our another number, by just doing xor of this 3 with our result which was 6, we get 5, which is our another answer
*/