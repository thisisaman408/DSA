#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v, int x, int y)
{
    for (int i = x, j = y; i < j; i++, j--)
    {
        v.at(i) = v.at(i) + v.at(j);
        v.at(j) = v.at(i) - v.at(j);
        v.at(i) = v.at(i) - v.at(j);
    }
}
void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << " ";
    }
}
int main()
{
    vector<int> a;
    int n;
    int x, y;
    cout << "Enter the size of your array : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << "Enter the indexes between which you want to reverse the vector :" << endl;
    cin >> x >> y;
    reverse(a, x, y);
    display(a);
}
//there is a built in function in vectors as reverse(v.begin(),v.end())
