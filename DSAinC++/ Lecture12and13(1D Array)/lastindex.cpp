#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;

    cout << "Enter the number of elements in the vector: " << endl;
    cin >> n;

    cout << "Enter the elements of the vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }

    int x;
    cout << "Enter the value to search for (x): ";
    cin >> x;

    int index = -1;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (x == v.at(i))
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "The last occurrence of " << x << " is at index: " << index << endl;
    }
    else
    {
        cout << x << " is not found in the vector." << endl;
    }

    return 0;
}
