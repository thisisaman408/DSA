/*
    Q4 You are given a positive integer n, you can do the following operation any number of
times:
Add or subtract a power of 2 from n.
Return the minimum number of operations to make n equal to 0.

A number x is power of 2 if x == 2^i where i >= 0.
*/

/*

Solution



    Approach
Understanding the Operations:

Each operation involves adding or subtracting a power of 2 from n.
Therefore, any number can be represented in binary, and each bit in the binary representation corresponds to a power of 2.
Binary Representation Insight:

The number of operations needed to make n zero is directly related to the number of 1 bits in the binary representation of n.
This is because each 1 in the binary representation corresponds to a power of 2 that needs to be either added or subtracted to eventually reduce n to zero.
Key Insight
To transform a number n to zero, you need to perform operations corresponding to each 1 bit in its binary representation. This is equivalent to finding the Hamming weight (or population count) of the number, which is the count of 1 bits.
*/
#include <iostream>
using namespace std;

// Function to count the number of 1 bits in the binary representation of n
int countBits(int n)
{
    int count = -1;
    while (n > 0)
    {
        // Increment count if the least significant bit is 1
        count += (n & 1);
        // Right shift n by 1 to process the next bit
        n >>= 1;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    int result = countBits(n);
    cout << "Minimum number of operations to make " << n << " equal to 0: " << result << endl;

    return 0;
}
