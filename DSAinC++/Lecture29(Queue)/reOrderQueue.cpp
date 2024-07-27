#include <iostream>
#include <stack>
#include <queue>

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

void display(queue<int> q)
{
    while (q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    display(q);

    // 1 2 3 4 5 6 7 8 this is how queue is looking
    // 1 5 2 6 3 7 4 8 this is the required answer
    stack<int> st;
    int n = q.size() / 2;
    while (n--)
    {
        int x = q.front();
        q.pop();
        pushAtBottom(st, x);
    }
    // 5 6 7 8

    // 1 2 3 4 this is how stack top to bottom
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        q.push(x);
        q.push(q.front());
        q.pop();
    }
    display(q);
}