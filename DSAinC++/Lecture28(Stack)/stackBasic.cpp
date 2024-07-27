#include <iostream>
#include <stack>
using namespace std;
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
    while (st.size())
    {
        cout << st.top() << " ";
        st.pop();  
    }
}