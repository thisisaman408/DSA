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
int main()
{
    stack<int> st;
    cout << st.size() << endl;
    st.push(1);
    st.push(10);
    st.push(8);
    st.push(89);
    cout << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.size() << " " << st.top() << endl;
    pushAtBottom(st, 123);
    display(st);
}