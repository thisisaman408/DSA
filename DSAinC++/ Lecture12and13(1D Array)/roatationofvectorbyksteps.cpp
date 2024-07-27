#include <iostream>
#include <vector>
using namespace std;
void reversePart(vector<int> &a, int x, int y)
{
    for (int i = x, j = y; i < j; i++, j--)
    {
        a.at(i) = a.at(i) + a.at(j);
        a.at(j) = a.at(i) - a.at(j);
        a.at(i) = a.at(i) - a.at(j);
    }
}
void rotation(vector<int> &v, int k)
{
    reversePart(v, 0, v.size() - k - 1);
    reversePart(v, v.size() - k, v.size() - 1);
    reversePart(v, 0, v.size() - 1);
}
void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
}
int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;
    cout << "Enter your array elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cout << "Enter the value of k (rotation): " << endl;
    cin >> k;
    if (k > n)
    {
        k = k % n;
    }

    rotation(v, k);
    display(v);
}

/*
ALgo is like
for k = 2
1 2 3 4 5 6 7
starting ke elements(last ke k element chor ke yaah pe 6 and 7),
unhe reverse karo
5 4 3 2 1 6 7
ab last walo ko reverse karo
5 4 3 2 1 7 6
ab ise pura reverse karo
6 7 1 2 3 4 5
required answer
*/