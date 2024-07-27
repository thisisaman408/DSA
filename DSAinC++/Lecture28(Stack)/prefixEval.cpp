#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

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

int evaluatePrefix(string &s)
{
    stack<int> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0'); // Convert char to int
        }
        else
        {
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.pop();
            int p = applyOperation(top1, top2, s[i]);
            st.push(p);
        }
    }
    return st.top();
}

int main()
{
    string expression = "-/*+79483";
    cout << "Result: " << evaluatePrefix(expression) << endl;
    return 0;
}
