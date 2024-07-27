#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (i == j)
        {
            if (nums[i] >= 1 && nums[j] <= 1)
            {
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
            }
            break;
        }
        else if (nums[i] < 1)
        {
            i++;
        }
        else if (nums[j] > 1)
        {
            j--;
        }
        else if (nums[i] > 1 && nums[j] < 1)
        {
            nums[i] = nums[i] + nums[j];
            nums[j] = nums[i] - nums[j];
            nums[i] = nums[i] - nums[j];
            i++;
            j--;
        }
        else if (nums[i] > 1 && nums[j] == 1)
        {
            nums[i] = nums[i] + nums[j];
            nums[j] = nums[i] - nums[j];
            nums[i] = nums[i] - nums[j];
            i++;
            j--;
        }
        else if (nums[i] == 1 && nums[j] == 1)
        {
            i++;
            j--;
        }
    }
}

int main()
{
    vector<int> nums;
    nums.push_back(0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    sort(nums);
    n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
