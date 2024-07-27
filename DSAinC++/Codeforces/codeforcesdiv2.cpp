#include <iostream>
using namespace std;
int n, m, f[10003], g[10003];
int p[10003], q[10003], N, M;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i], p[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> q[i], q[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (p[i] != i)
            for (int j = i + 1; j < n; j++)
            {
                if (p[j] == i)
                {
                    f[N++] = i + 1;
                    f[N++] = j - i;
                    swap(p[i], p[j]);
                }
            }
    }
    for (int i = 0; i < m; i++)
    {
        if (q[i] != i)
            for (int j = i + 1; j < m; j++)
            {
                if (q[j] == i)
                {
                    g[M++] = i + 1;
                    g[M++] = j - i;
                    g[M++] = m - j;
                    swap(q[i], q[j]);
                }
            }
    }
    if ((N + M & 1) && n % 2 == 0 && m % 2 == 0)
    {
        cout << -1;
        return 0;
    }
    if ((N + M & 1) && n % 2 == 1)
    {
        for (int i = 0; i < n; i++)
            f[N++] = 1;
    }
    if ((N + M & 1) && m % 2 == 1)
    {
        for (int i = 0; i < m; i++)
            g[M++] = 1;
    }
    while (N < M)
    {
        f[N++] = 1, f[N++] = n;
    }
    while (N > M)
    {
        g[M++] = 1, g[M++] = m;
    }
    cout << N << '\n';
    for (int i = 0; i < N; i++)
    {
        cout << f[i] << ' ' << g[i] << '\n';
    }
}
/*HERE consider the problem as there are two groups of numbers
one group say p and another group as   q. now each group has some elementsw
which are named and denoted by numbers,now these elements are not in order
we want both of them to be in order (correct order),now how shall we do it?
basically we need to sort the permutation, and will declare a counter here, and after that
that counter will go count++, it is so because we want to calculate the total ways in which we can perform
this task, and in this task we do not need to minimise the no of operation*/