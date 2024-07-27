#include <iostream>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    cout << "Enter the number of terms upto which you want the sum : " << endl;
    cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (i % 2 != 0)
    //     {
    //         sum += i;
    //     }
    //     else
    //     {
    //         sum -= i;
    //     }
    // }
    // cout <<"The sum is "<< sum << endl;
    // this is not a good approach this problem now see

    if (n % 2 == 0)
    {
        sum = -n / 2;
    }
    else
    {
        sum = -n / 2 + n;
    }
    cout << "The sum is " << sum << endl;
}
/*
Basicaly here we divided the numbers into pairs
(1-2) + (3-4) + (5-6)........and so on
this is how OUR series looks like and sum of each pairs is noting but -1
so if the number of these pairs is n
then ans is simply -n/2
but if it is odd then
ans should be -n/2 +n and it is not n/2
it is because -n/2 gives an integer value
*/