#include <iostream>
#include <vector>
using namespace std;
void swap(int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}
void reverse(vector<int> &v, int i, int j)
{
    int n = v.size();
    while (i <= j)
    {
        swap(&v[i], &v[j]);
        i++;
        j--;
    }
}
void nextpermutation(vector<int> &v)
{
    int n = v.size();
    int index = -1;
    for (int j = n - 2; j >= 0; j--)
    {
        if (v[j] < v[j + 1])
        {
            index = j;
            break;
        }
    }
    if (index == -1)
    {
        reverse(v, 0, n - 1);
        return;
    }
    reverse(v, index + 1, n - 1);
    int swapp = 0;
    for (int i = index + 1; i < n; i++)
    {
        if (v[i] >= v[index])
        {
            swapp = i;
            break;
        }
    }
    swap(&v[index], &v[swapp]);
}
void display(vector<int> &v)
{

    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v.at(i) << " ";
    }
}
int main()
{
    vector<int> v;
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter your elements  : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "Next permutation is : " << endl;
    nextpermutation(v);
    display(v);
}