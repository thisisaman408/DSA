/*this coce will print odd numbers ,as we are skipping the 2nd iteration*/

#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 0)
            continue;
        cout << i << " ";
    }
}
/*break means ki loop se bahar aaa jao but continue statement means
us particular iteration ko pass kar do and move on to next iteration
it is like here i = 2 par continue hit hua to due to continue statement
wo iteratioin skip huii and if statement jumps to i = 3 iteration
this is the function of continue statement*/