#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;
    cout << "Enter the elements of your array : " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "Your elements in reverse order as follows" << endl;
    vector<int> v2(v.size());
    for (int i = 0; i < v2.size(); i++)
    {
        int j = v.size() - 1 - i;
        v2[i] = v[j];
        cout << v2[i] << " ";
    }
}