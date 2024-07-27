// #include<iostream>
// using namespace std;
// int main( ) {
// int a = 5, b, c ;
// b = a = 15 ;
// c = a < 15 ;
// cout << "a = " << a << ", b = " << b << " , c = "<< c ;
// return 0;
// }

/*
here first it is checked that is a < 15, which is false or 0
in binary, so c is set to zero and that's why we get output as 0
in c = 0*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int x = 3;
//     float y = 3.0;
//     if (x == y)
//         cout << "x and y are equal";
//     else
//         cout << "x and y are not equal";
//     return 0;
// }
/*
in c++, int is automatically promoted to float whenever needed
*/
// #include<iostream>
// using namespace std;
// int main(){
// int test = 0;
// cout << "First character " << '1' << endl;
// cout << "Second character " << (test ? 3 : '1') << endl;
// return 0;
// }
/*
here test = 0 which means false, so when 1st cout is
executed it prints the 1 as it is a string,
when 2nd cout is executed it is character as test is false
so else value will get printed in ternary operator,
so ASCII value of character '1' is 49 so 1 and 49 shall be printed*/
// #include <iostream>
// using namespace std;
// int main(){
// int a = 18; int b = 12;
// bool t = (a > 20 && b < 15)? true : false;
// cout <<"Value of t: " << t ;
// return 0;
// }
/*here in && operator, && do not check any other condition if first condiotion is  false,
so here a > 20 is a false statement so the whole statement is false, && won't check b > 15
condition, so false statement is executed hence t = false, which is 0*/
// #include <iostream>
// using namespace std;
// int main()
// {
//     int number = -4;
//     char result;
//     result = number > 0 ? 'P' : 'N';
//     cout << result << endl;
//     return 0;
// }
/*here no ASCII value is printed as result is declared as character
if result is int then ASCII value should have printed*/
// #include <iostream>
// using namespace std;
// int main() {
// while ('1' < '2')
// cout << "In while loop" << endl;
// }
/*this is an infinite loop as ASCII value of '1' is always less than '2'*/
// #include <iostream>
// using namespace std;
// int main( ) {
// int t = 10;
// while (t /= 2) {
// cout << "Hello" << endl;
// }
// }
/*10/2 = 5, 5/2 = 2, 2/2 = 1, 1/2 = 0, here loop exits*/
// #include <iostream>
// using namespace std;
// int main( ) {
// int x = 10, y = 0 ;
// while ( x >= y ) {
// x-- ;
// y++ ;
// cout << x << " " << y << endl ;
// }
// }
/*
pehle value kam ho rhi and then print ho rhi hai isiliye 4 6 v print hua*/

// int main()
// {
//     int n;
//     cout << "Enter your number : " << endl;
//     cin >> n;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 65; j <= 64 + i; j++)
//         {
//             if (i % 2 != 0)
//             {
//                 cout << j - 64;
//             }
//             else
//             {

//                 cout << (char)j;
//             }
//         }
//         cout << endl;
//     }
// }
// int main()
// {

//     int n;
//     cout << "Enter the no of rows : " << endl;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
//     for (int i = 1; i <= n - 1; i++)
//     {
//         for (int j = n - 1; j >= i; j--)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }
// int main()
// {

//     int n, m;
//     cout << "Enter the no of rows : " << endl;
//     cin >> n;
//     cout << "Enter the no of columns : " << endl;
//     cin >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (j == 1 || i == 1 || i == n || j == m)
//             {
//                 cout << "*";
//             }
//             else
//             {
//                 cout << " ";
//             }
//         }
//         cout << endl;
//     }
// }
// int main()
// {

//     int n, m;
//     cout << "Enter the no of rows : " << endl;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int k = n; k >= i; k--)
//         {
//             cout << " ";
//         }
//         for (int j = 1; j <= n; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }
// int main()
// {

//     int n;
//     cout << "Enter the no of rows : " << endl;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << j;
//         }
//         cout << endl;
//     }
// }
// int main()
// {

//     int n;
//     cout << "Enter the no of rows : " << endl;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int k = n; k >= i; k--)
//         {
//             cout << " ";
//         }
//         for (int j = 65; j <= 64 + i; j++)
//         {
//             cout << (char)j;
//         }
//         cout << endl;
//     }
// }
// int main()
// {

//     int n;
//     cout << "Enter the no of rows : " << endl;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << " ";
//         }
//         for (int k = 1; k <= i; k++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
//     for (int l = 1; l <= n - 1; l++)
//     {
//         for (int m = 1; m <= l; m++)
//         {

//             cout << " ";
//         }
//         for (int p = n - 1; p >= l; p--)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int a = 10, b = 20;
//     int *ptr = &a;
//     b = *ptr + 1;
//     ptr = &b;
//     cout << *ptr << " " << a << " " << b;
#include <iostream>
#include <vector>
using namespace std;
// int main()
// {
//     int a[][2] = {{1, 2}, {3, 4}};
//     int i, j;
//     for (i = 0; i < 2; i++)
//         for (j = 0; j < 2; j++)
//             cout << a[i][j];
//     return 0;
// }
int main ()
{
    float x = -4.9;
    cout <<(int)x;

}