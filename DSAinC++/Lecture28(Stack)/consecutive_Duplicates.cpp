#include <iostream>
#include <stack>
#include <algorithm> // for reverse
using namespace std;

string final(string &s)
{
    int i = 0;
    stack<char> st;
    while (i < s.size())
    {
        if (!st.empty() && st.top() == s[i]) // Check if stack is empty before accessing top
        {
            i++;
            continue;
        }
        else
        {
            st.push(s[i]);
        }
        i++;
    }

    s = "";
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string s = "aaabbbcddde";
    cout << final(s);
}
