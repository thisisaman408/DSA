#include <iostream>
using namespace std;
int no_of_set_bits(int num)
{
    return __builtin_popcount(num); // built in function to count the no of 1 in binary form of a number
}
int custom_count_of_set_bits(int num) // brian kernigal's algorithm
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num = num & (num - 1);
    }
    return count;
}
int main()
{
    cout << no_of_set_bits(5) << endl;
    cout << custom_count_of_set_bits(11) << endl;
}