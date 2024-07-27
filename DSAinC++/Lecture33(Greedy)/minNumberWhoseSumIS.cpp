/*
 Q2 Given an integer k, return the minimum number of Fibonacci numbers whose sum is
equal to k. The same Fibonacci number can be used multiple times.


The Fibonacci numbers are defined as:
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 for n > 2.
It is guaranteed that for the given constraints we can always find such Fibonacci numbers
that sum up to k.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> generateFibonacci(int n)
{
    vector<int> fibNumbers;

    fibNumbers.push_back(1);
    fibNumbers.push_back(1);

    int a = 1, b = 1;
    while (1)
    {
        int next = a + b;
        if (next > n)
        {
            break;
        }
        fibNumbers.push_back(next);
        a = b;
        b = next;
    }

    return fibNumbers;
}
int main()
{
    int k = 19;
    int ans = 0;
    vector<int> f = generateFibonacci(k);
    for (int i = 0; i < f.size(); i++)
    {
        cout << f[i] << " ";
    }
    cout << endl;
    for (int i = f.size() - 1; i >= 0; i--)
    {
        while (k >= f[i])
        {
            k -= f[i];
            ans++;
        }
        if (k == 0)
            break;
    }
    cout << ans;
}