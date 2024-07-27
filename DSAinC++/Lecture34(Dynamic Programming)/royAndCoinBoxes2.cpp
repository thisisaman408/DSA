/*

this is approach 2,

in the previous approach, we made two different arrays for L and R, then calculated the
dp[i] by a recurrence l[i] - r[i-1] + f[i-1], here we do need to do anything such,
rest code is same basically we will create dp array, with new technique, rest using c array
and calulating the suffix sum is same as before


for ex, we have to process querry 1 3, 1 to 3,
so i will add 1 to every coin box after 1 (including 1),and then add -1 to every box
after 3, basically L and R,

and at the end I will just take preix sum, and I will be getting the same dp array I needed


*/

/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.

Input:
First line contains N - number of coin boxes.
Second line contains M - number of days.
Each of the next M lines consists of two space separated integers L and R.
Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X


https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;                  // no of coin boxex
    vector<int> dp(n + 10, 0); // an array for coin boxex
    int m;                     // no of days
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int L, R;
        cin >> L >> R;
        dp[L]++;
        dp[R + 1]--;
    }

    // just simply calculate prefix sum

    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = dp[i] + dp[i - 1];
    }

    // do not get confused, till now, we have just put the coins, in their respective boxes as per the question
    // now we are just making it easy and in O(1), to get the answer, how many boxes has atleast 2 coins, so
    // right now, we might have to travel in the entire array
    vector<int> c(1000005, 0);
    // so created another array, which will consider the no of coins before as the index

    for (int i = 0; i <= n; i++)
    {
        c[dp[i]]++;
        // think it like, in dp array at 4th index there is 5, so as per our question, what we
        // stored in our dp array? in the box no 4 there are 5 coins,  so what are we doing im this
        // c vector?, we are basically going to the index 5, and updating how many boxes has coin 5?
        // like go to index 5 and update it everytime you get a box with coins = 5, got it??
    }
    // now we know that, c has the data , for example if at index 7 there is 4, so
    // we will read it as, there are 4 boxes who has 7 coins, but is it?? final answer NO
    //  then?? we had to calculate the atleast how many boxes has x no of coins?? right
    //  here index is the no of coins, so if 4th index has 5 , so 4 coins are in 5 boxes, next
    // say 5th index has 10, so 5 coins are in 10 boxes, but wait?,  does this mean,
    // 4 coins are also available in these 10 boxes more? I mean if 10 boxes have 5 coins
    // then ofcourse they also have 4 coins, so from here, we can see that as the no of indexes
    // will always increase so we have to CALCULATE THE SUFFIX SUM

    // so calclulate it

    for (int i = c.size() - 2; i >= 0; i--)
    {
        c[i] = c[i] + c[i + 1];
    }

    // now we have our answer

    // let us accept the queries now
    int q;
    cin >> q; // no of queries
    while (q--)
    {
        int num;
        cin >> num;
        // these will be basically the numbers, for example 4,5,6,2,
        // like how many boxes has atleast 4,5,6 and 2 coins respectively

        cout << c[num] << endl;
    }
}