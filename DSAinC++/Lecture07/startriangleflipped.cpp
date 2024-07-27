#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the no of rows : " << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
/*n+1-i ye condition use hoti thi...reversed triangle
print krne mai....now mujhe last wali row m star nhi
chaiye...actually mai yaha reverse space print krne wala hu
and last row m i do not want any spaces, that's why n-1

ab mujhe stars v print krne hai...to ek or loop chala do 
to print stars ham whi code use kr rhe hai reversed traingle wla,bss
isme pehle hi space print kr rhe*/