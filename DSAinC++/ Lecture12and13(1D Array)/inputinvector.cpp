#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(1); // we should give an initial size to just start the process, this could be 1
    cout << "Enter your elements : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        char ch;
        cout << "Do you want to stop adding elements?" << endl;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            break;
        }
    }
    for (int i = 1; i < v.size(); i++)
    {

        cout << v.at(i) << " ";
    }
}