#include <iostream>
using namespace std;
void subset(string ans, string original)
{
    if(original == ""){
        cout<< ans<<endl;
        return;
    }
    char ch = original[0];
    subset(ans + ch, original.substr(1));
    subset(ans, original.substr(1));
}
int main()
{
    string s = "ab";
    subset("", s);
}
// it's a simple recursion, but i will recommend to dry run it, and it will really help to imagine