#include <iostream>
#include <vector>
using namespace std;
int inversion(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] > 2*b[j])
        {
            count += (a.size() - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return count;
}
void merge(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {

        if (a[i] < b[j])
        {
            res[k++] = a[i++];
        }
        else if (a[i] == b[j])
        {
            res[k++] = a[i++]; // stable, this  makes this algo stable
            j++;
        }
        else
        {
            res[k++] = b[j++];
        }
    }
    if (i == a.size())
        while (j < b.size())
            res[k++] = b[j++];
    if (j == b.size())
        while (i < a.size())
            res[k++] = a[i++];
}
int mergeSort(vector<int> &a)
{
    int n = a.size();
    int count = 0;
    if (n == 1)
        return 0;
    int n1 = n / 2;
    vector<int> b(a.begin(), a.begin() + n1);
    vector<int> c(a.begin() + n1, a.end());

    count += mergeSort(b);
    count += mergeSort(c);

    count += inversion(b, c);
    merge(b, c, a);

    // we can decrease the space complexity by deleting the newly formed vectors, after merging
    // them toghether
    b.clear();
    c.clear();
    return count;
}

int main()
{

    vector<int> b = {5, 1, 3, 0, 4, 9, 6}; // 4 + 1 + 1 + 1
    cout << mergeSort(b);
}