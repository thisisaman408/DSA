#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << " ";
    }
}
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
    // reverse
    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
    {
        v.at(i) = v.at(i) + v.at(j);
        v.at(j) = v.at(i) - v.at(j);
        v.at(i) = v.at(i) - v.at(j);
    }
    display(v);
}