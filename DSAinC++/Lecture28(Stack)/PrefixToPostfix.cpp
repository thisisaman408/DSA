#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

string applyOperation(string a, string b, char op)
{
    string s = "";
    s += a;
    s += b;
    s.push_back(op);

    return s;
}

string PostfixToPrefix(string &s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string p = applyOperation(top1, top2, s[i]);
            st.push(p);
        }
    }
    return st.top();
}

int main()
{
    string expression = "-/*+79483";
    cout << "Result: " << PostfixToPrefix(expression) << endl;
    return 0;
}
