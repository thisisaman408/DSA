#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> &res)
{

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
void merge(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else if (a[i] == b[j])
        {
            c[k++] = b[j++];
            i++;
        }
        else
            c[k++] = b[j++];
    }
    if (i == a.size())
        while (j < b.size())
            c[k++] = b[j++];
    if (j == b.size())
        while (i < a.size())
            c[k++] = a[i++];
    print(c);
}

int main()
{
    vector<int> a = {1, 3, 4, 5, 6};
    vector<int> b = {3, 5, 7, 12, 34, 67};
    vector<int> res((a.size()) + (b.size()));
    merge(a, b, res);
}