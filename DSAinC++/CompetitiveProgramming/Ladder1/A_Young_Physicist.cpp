#include<iostream>
#include<vector>

using namespace std;
int suma = 0;
int sumb = 0;
int sumc = 0;
int main(){
    int n;
    cin>>n;

    for(int i= 0; i < n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        suma +=a;
        sumb +=b;
        sumc += c;
    }
    if(suma != 0 or sumb != 0 or sumc != 0) {
            cout<<"NO";
        }
    else cout<<"YES";
}