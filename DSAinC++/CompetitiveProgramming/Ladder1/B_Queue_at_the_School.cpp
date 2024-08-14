#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<char> s(n);
    for (int i = 0; i < n; i++)
    {
        char a;
        cin>>a;
        s[i] = a;
    }
    // for(int i=0;i<n;i++) cout<<s[i];
    cout<<endl;
    while (t--)
    {
        for(int i = 0; i < n;i++){
            if(s[i] == 'B' && s[i+1] == 'G'){
                swap(s[i],s[i+1]);
                i++;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<s[i];
}
