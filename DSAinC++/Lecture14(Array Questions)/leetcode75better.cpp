#include <iostream>
#include <vector>
using namespace std;
void dutchalgorithm(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (nums.at(mid) == 2)
        {
            nums.at(mid) = nums.at(mid) + nums.at(high);
            nums.at(high) = nums.at(mid) - nums.at(high);
            nums.at(mid) = nums.at(mid) - nums.at(high);
            high--;
        }
        if (nums.at(mid) == 0)
        {
            nums.at(mid) = nums.at(mid) + nums.at(low);
            nums.at(low) = nums.at(mid) - nums.at(low);
            nums.at(mid) = nums.at(mid) - nums.at(low);
            low++;
            mid++;
        }
        if (nums.at(mid) == 1)
        {
            mid++;
        }
    }
}
void display(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
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
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    dutchalgorithm(v);
    display(v);
}