/*
There is a bag that consists of items, each item has a number 1, 0, or -1 written on it.

Example 1:

Example 2:
Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
Output: 2

Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
Output: 3
Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 2
items with 1 written on them and get a sum in a total of 2.
It can be proven that 2 is the maximum possible sum.

Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 3
items with 1 written on them, and 1 item with 0 written on it, and get a sum in a total of 3.
It can be proven that 3 is the maximum possible sum.
*/

#include <iostream>

using namespace std;

int main()
{
    int numOnes = 3;
    int numZeroes = 2;
    int numNegOnes = 0;
    int k = 4;
    int sum = 0;
    // we have to pick k items, with maximizing the sum written on it
    while (k--)
    {
        if (numOnes > 0)
        {
            sum += 1;
            numOnes--;
        }
        else if (numZeroes > 0)
        {
            sum += 0;
            numZeroes--;
        }
        else
        {
            sum += -1;
            numNegOnes--;
        }
    }
    cout << sum << endl;
}