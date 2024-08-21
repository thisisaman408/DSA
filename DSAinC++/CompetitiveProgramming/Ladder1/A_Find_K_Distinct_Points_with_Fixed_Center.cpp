#include<iostream>
using namespace std;

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        int xc,yc,k;
        cin>>xc>>yc>>k;
        for(int i=1;i<=k;i++){
            cout<<min(xc,k)<<" "<<min(yc,k)<<endl;
        }
    }
}