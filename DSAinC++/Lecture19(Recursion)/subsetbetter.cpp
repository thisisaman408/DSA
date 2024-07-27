#include <iostream>
using namespace std;
void subset(string ans, string original, int index)
{
    if(index == original.size()){
        cout << ans <<endl;
        return;
    }
    char ch = original[index];
    subset(ans + ch, original, index + 1);
    subset(ans,original, index + 1);
}

int main()
{
    string s = "abc";
    subset(" ", s, 0);
}