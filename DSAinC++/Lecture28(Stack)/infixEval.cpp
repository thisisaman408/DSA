#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

int priority(char s)
{
    if (s == '*' || s == '/')
        return 2;
    else
        return 1;
}

int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

int infixEval(string &s)
{
    stack<int> st;
    stack<char> op;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else if (op.empty() || priority(s[i]) > priority(op.top()))
        {
            op.push(s[i]);
        }
        else
        {
            while (!op.empty() && priority(s[i]) <= priority(op.top()))
            {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                char top = op.top();
                op.pop();
                int ans = applyOperation(top2, top1, top);
                st.push(ans);
            }
            op.push(s[i]);
        }
    }
    while (!op.empty())
    {
        int top1 = st.top();
        st.pop();
        int top2 = st.top();
        st.pop();
        char top = op.top();
        op.pop();
        int ans = applyOperation(top2, top1, top);
        st.push(ans);
    }
    return st.top();
}

int main()
{
    string expression = "3+5*2";
    cout << "Result: " << infixEval(expression) << endl;
    return 0;
}
