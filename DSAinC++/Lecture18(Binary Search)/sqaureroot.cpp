#include <iostream>
using namespace std;
int squareroot(int x)
{
    int low = 1;
    int high = x;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midsquare = mid * mid;
        if (midsquare == x)
        {
            return mid;
        }
        else if (midsquare < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
    //we are returning high, because when low > high at that moment, loop will break, 
    //so, high will always be the nearest square root of the given number, example 20
}
int main()
{
    int x;
    cout << "Enter the number : ";
    cin >> x;
    int sq = squareroot(x);
    cout <<sq;
}

//here when we are having 20, our low = 1, and high = 20,then mid = 10
/*
Now, here midsq  = 100
100 != 20,
100 > 20, thus high = mid - 1 = 9
high = 9, and low = 1
now, mid = 5
25 != 20
thus again ,high = mid - 1 = 4
then mid =  2
4 < 20
thus low = mid  + 1 = 3
high = 4
mid = 3
9 < 20
thus low = mid  + 1 = 4
but now, low = high
thus loop breaks
and we get 4 as answer as it is high so we are returning high

*/
