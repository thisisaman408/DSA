#include <iostream>
using namespace std;
class Stack
{
public:
    int arr[10];
    int idx;
    Stack() : idx(0) {}

    void push(int val)
    {
        if (idx > 10)
        {
            cout << "Stack Overflow";
        }
        else
        {
            arr[++idx] = val;
        }
    }
    void pop()
    {
        if (idx == 0)
            cout << "Stack underflow";
        else
            idx--;
    }

    int top()
    {
        return arr[idx];
    }
    void display()
    {
        if (idx == 0)
        {
            return;
        }
        int x = top();
        cout << x << " ";
        pop();
        display();
        push(x);
    }

    int size()
    {
        return idx;
    }
};
int main()
{

    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << st.top();
    cout << endl;
    st.display();
    cout << st.size();
    st.pop();
    cout << endl;
    cout << st.top();
    cout << endl;
    st.display();
    cout << endl;
    cout << st.size();
}