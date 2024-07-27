#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void triplet(vector<int> &v, int p)
{
    int n = v.size();
    sort(v.begin(), v.end());
    bool found = false;

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int current_sum = v[i] + v[left] + v[right];
            if (current_sum == p)
            {
                cout << "(" << v[i] << "," << v[left] << "," << v[right] << ")" << endl;
                found = true;
                left++;
                right--;
            }
            else if (current_sum < p)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    if (!found)
    {
        cout << "No such triplets found" << endl;
    }
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter array elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int target;
    cout << "Enter the target element : " << endl;
    cin >> target;
    triplet(v, target);
}
