#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] >= b[j])
            res[k++] = a[i++];
        else
            res[k++] = b[j++];
    }
    if (i == a.size())while(j < b.size())res[k++] = b[j++];
    if (j == b.size()) while(i < a.size()) res[k++] = a[i++];
}
void mergeSort(vector<int> &v)
{
    int n = v.size();
    if (n == 1)
        return;
    int n1 = n / 2;
    vector<int> a(v.begin(), v.begin() + n1);
    vector<int> b(v.begin() + n1, v.end());
    mergeSort(a);
    mergeSort(b);

    merge(a, b, v);
    a.clear();
    b.clear();
}
int main()
{
    vector<int> b = {12, 34, 673, 5, 7, 2};
    mergeSort(b);
    for (int i = 0; i < b.size(); i++)
    {

        cout << b[i] << " ";
    }
}