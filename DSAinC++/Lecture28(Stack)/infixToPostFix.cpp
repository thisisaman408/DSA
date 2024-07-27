#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

int priority(char s)
{
    if (s == '*' || s == '/')
        return 2;
    else if (s == '+' || s == '-')
        return 1;
    else
        return 0;
}

string infixToPost(string &s)
{
    stack<string> st;
    stack<char> op;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else if (s[i] == '(')
        {
            op.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                char top = op.top();
                op.pop();
                string ans = top2 + top1 + string(1, top);
                st.push(ans);
            }
            op.pop(); // Remove the '(' from the stack
        }
        else if (op.empty() || op.top() == '(' || priority(s[i]) > priority(op.top()))
        {
            op.push(s[i]);
        }
        else
        {
            while (!op.empty() && priority(s[i]) <= priority(op.top()))
            {
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                char top = op.top();
                op.pop();
                string ans = top2 + top1 + string(1, top);
                st.push(ans);
            }
            op.push(s[i]);
        }
    }

    while (!op.empty())
    {
        string top1 = st.top();
        st.pop();
        string top2 = st.top();
        st.pop();
        char top = op.top();
        op.pop();
        string ans = top2 + top1 + string(1, top);
        st.push(ans);
    }

    return st.top();
}

int main()
{
    string expression = "(7+9)*4/8-3";
    cout << "Result: " << infixToPost(expression) << endl;
    return 0;
}
