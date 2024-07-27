#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int p;
    cout << "Enter the number whose doublet you want: ";
    cin >> p;

    bool flag = false;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] + v[j] == p)
            {
                cout << i << " " << j << endl;
                flag = true;
            }
        }
    }

    if (flag == false)
    {
        cout << "No such doublets found." << endl;
    }

    return 0;
}
