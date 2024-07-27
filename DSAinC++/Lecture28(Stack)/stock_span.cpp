#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> stock_span(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(0);
    ans[0] = 1;

    for (int i = 1; i < n; i++)
    {
        while (st.size() > 0 && v[st.top()] <= v[i])
            st.pop();
        ans[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }

    return ans;
}
int main()
{
    vector<int> v = {100, 80, 60, 81, 70, 60, 75, 85};
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    v = stock_span(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}