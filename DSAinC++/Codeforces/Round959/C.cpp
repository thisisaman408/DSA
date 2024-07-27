#include <cstdio>
#include <vector>
using namespace std;

int countValidSubsegments(const vector<int> &a, int x)
{
    int n = a.size();
    int count = 0;

    for (int l = 0; l < n; ++l)
    {
        int current_toxicity = 0;
        for (int r = l; r < n; ++r)
        {
            current_toxicity += a[r];
            if (current_toxicity > x)
            {
                current_toxicity = 0;
            }
            if (current_toxicity > 0)
            {
                ++count;
            }
        }
    }

    return count;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, x;
        scanf("%d %d", &n, &x);

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }

        int result = countValidSubsegments(a, x);
        printf("%d\n", result);
    }

    return 0;
}
