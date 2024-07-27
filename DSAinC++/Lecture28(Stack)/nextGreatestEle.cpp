#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void nextGreatestNumber(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(v[n - 1]);
    ans[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= v[i])
        {
            st.pop();
        }
        if (st.size() == 0)
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(v[i]);
    }
    v = ans;
}
void prevGreatestNumber(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(v[0]);
    ans[0] = -1;
    int maxx = 0;
    int finalMax = INT_MIN;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        maxx = v[i];
        if (finalMax < maxx)
        {
            k = i;
            finalMax = maxx;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        while (st.size() > 0 && st.top() <= v[i])
            st.pop();
        if (st.size() == 0)
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(v[i]);
    }
    for (int i = k + 1; i < n; i++)
    {
        ans[i] = finalMax;
    }
    v = ans;
}
int main()
{
    vector<int> v = {3, 1, 2, 7, 4, 6, 2, 3};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    nextGreatestNumber(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // prevGreatestNumber(v);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
}