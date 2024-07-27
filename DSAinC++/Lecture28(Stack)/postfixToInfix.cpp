#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

string applyOperation(string a, string b, char op)
{
    string s = "";
    s += a;
    s.push_back(op);
    s += b;
    return s;
}

string PostfixToInfix(string &s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
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
            string p = applyOperation(top2, top1, s[i]);
            st.push(p);
        }
    }
    return st.top();
}

int main()
{
    string expression = "79+4*8/3-";
    cout << "Result: " << PostfixToInfix(expression) << endl;
    return 0;
}
