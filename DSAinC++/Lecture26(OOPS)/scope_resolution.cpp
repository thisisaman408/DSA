#include <iostream>
using namespace std;
int b = 5;
int main()
{
    int b = 10;
    cout<<b<<endl;
    //it will print 10, as here the scope of 10 exist, 

    cout<<::b;
    //this will print 5, as this tells about the scope, as we used in oops as Bike::b, so it will use the b of the class variable
}