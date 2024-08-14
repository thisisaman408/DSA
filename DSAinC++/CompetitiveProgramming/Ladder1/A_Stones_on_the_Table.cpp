#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<char>s;
    for(int i= 0; i<n;i++){
            char a;
            cin>>a;
            s.push_back(a);
    }
    int count = 0;
    for (int i = 1; i < s.size(); i++)  if (s[i-1] == s[i])   count++;
    cout << count;
}