#include <iostream>
#include <vector>
using namespace std;
void sort(vector<int> &v)
{
    int noz = 0;
    int noo = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i) == 0)
        {
            noz++;
        }
        else
        {
            noo++;
        }
    }
    for (int i = 0; i < noz; i++)
    {
        v.at(i) = 0;
    }
    for (int i = noz; i < v.size(); i++)
    {
        v.at(i) = 1;
    }
    for (int i = 0; i < v.size(); i++)
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
    cout << "Enter the elements in 0 and 1" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v);
}