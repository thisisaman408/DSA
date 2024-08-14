#include<iostream>
using namespace std;

int main(){
    char a;
    while(cin>>a){
        if(a == '.'){
            cout<<0;
        }
        else if (a == '-'){
            char b;
            cin>>b;
            if(b == '.'){
                cout<<1;
            }
            else cout<<2;
        }
    }
}