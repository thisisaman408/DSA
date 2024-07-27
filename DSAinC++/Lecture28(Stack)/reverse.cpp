#include <iostream>
#include <stack>
using namespace std;
void pushAtBottom(stack<int> &st, int val)
{
    if (st.size() == 0)
    {
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottom(st, val);
    st.push(x);
}
void display(stack<int> &st)
{
    if (st.size() == 0)
        return;
    int x = st.top();
    cout << st.top() << " ";
    st.pop();
    display(st);
    st.push(x);
}
void reverse(stack<int> &st)
{

    int x = st.top();
    if (st.size() == 1)
    {
        return;
    }
    st.pop();
    reverse(st);
    pushAtBottom(st, x);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(10);
    st.push(8);
    st.push(89);
    display(st);
    reverse(st);
    cout << endl;
    display(st);
}