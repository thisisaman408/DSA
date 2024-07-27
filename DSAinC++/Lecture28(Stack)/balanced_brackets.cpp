#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string &s)
{
    if(s.size() %2 != 0) return false;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if(s[i] == ')')
        {
            if (!s.size())
                st.pop();
        }
    }
    if (st.size() == 0)
        return true;
    return false;
}
int main()
{
    string s = "()";
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;

    s = "(()";
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;

    s = "(())";
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;

    s = "())(";
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}