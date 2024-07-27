#include <iostream>
#include <vector>
using namespace std;
vector<int> factorial(int n)
{
    int MOD = 10000007;
    vector<int> fact(n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        fact[i] = ((i % MOD) * (fact[i - 1] % MOD)) % MOD;
    }
    return fact;
}
int main()
{
    vector<int> v = factorial(25);
    for (int i = 0; i < v.size(); i++)
    {
        cout << i << "!"
             << " " << v[i] << endl;
    }
}