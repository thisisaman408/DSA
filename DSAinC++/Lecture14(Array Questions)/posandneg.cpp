#include <iostream>
#include <vector>
using namespace std;
void sort(vector<int> &v)
{
    int n = v.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (v.at(i) < 0)
        {
            i++;
        }
        if (v.at(j) > 0)
        {
            j--;
        }
        if (i > j)
        {
            break;
        }
        {
            v.at(i) = v.at(i) + v.at(j);
            v.at(j) = v.at(i) - v.at(j);
            v.at(i) = v.at(i) - v.at(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v.at(i) << " ";
    }
}
int main()
{
    vector<int> v;
    int n;
    cout << "Enter size of array : " << endl;
    cin >> n;
    cout << "Enter the elements positive and negaive" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v);
}