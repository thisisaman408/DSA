#include <iostream>
using namespace std;
class Calculator
{
public:
    int a;// data members
    int b;
    void add()
    {
        cout << "Sum is " << a + b << endl;
    }
    void subtract()//member functions
    {
        cout << "Differece is " << a - b << endl;
    }
    void Product()
    {
        cout << "Product is " << a * b << endl;
    }
    void Division()
    {
        cout << "Quotient will be " << (a / b) << endl;
    }
};
int main()
{
    Calculator calci;
    calci.a = 6;
    calci.b = 123;
    calci.add();
    calci.subtract();
    calci.Product();
    calci.Division();
}