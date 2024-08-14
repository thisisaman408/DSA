#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    string y;
    cin>>s>>y;
    int i=0;
    while(i<s.length()){
        if(s[i] == y[i]) cout<<0;
        else cout<<1;
        i++;
    }
}