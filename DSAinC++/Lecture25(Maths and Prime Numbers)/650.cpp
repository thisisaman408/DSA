#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int minSteps(int n)
    {
        int hf = 0;
        int nop = 0;
        if (isPrime(n))
        {
            nop += n;
            return nop;
        }
        if (!isPrime(n))
        {
            if (n % 2 == 0)
            {
                hf = n / 2;
                nop += 2;
            }
            else
            {
                int i = 1;
                for (i = 1; i <= sqrt(n); i++)
                {
                    if (n % i == 0)
                        continue;
                }
                hf = n / i;
                nop += 2;
            }
        }
        minSteps(hf);
        return nop;
    }
    int main()
    {
            cout<<minSteps(3);
    }
};
