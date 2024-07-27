#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findPrefixScore(vector<int> &nums)
{
    vector<int> conver(nums.size(),0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        auto maxEle = max_element(nums.begin(), nums.begin() + i + 1);
        cout<<*maxEle<<" ";
        if (maxEle != nums.end())
        {
            conver[i]= nums[i] + *maxEle;
        }
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << conver[i] << " ";
    }
}
int main()
{
    vector<int> nums = {2, 3, 7, 5, 10};
    findPrefixScore(nums);
}