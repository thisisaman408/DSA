// here we will take input and output from the class using constructor and not getter and setter

#include <iostream>
using namespace std;
class Bike
{
public:
    static int noOfBikes; // this variable belongs to the class, it will remain same for all the objects of this class
    int tyreSize;
    int engineSize;

    static void increaseNoOfBikes()
    {
        noOfBikes++;
    }
    // these are static fucntions, and these functions also belongs to class, if I  change it for one object
    // the value will get changed for all the objects, and even If I change it using the class, it will get changed for all the objects

    // this is a constructor
    // Bike(int tyreSize, int engineSize)
    // {
    //     this->tyreSize = tyreSize;
    //     this->engineSize = engineSize;
    // }
    // there is a shortcut to do the same above work using the initialisation list

    Bike(int tS, int eS) : tyreSize(tS), engineSize(eS)
    {
        // this will do the same work as the previous one, and this is considered as better option, to do initialisation
        //  this method is called initialisation list
    }
    //here we are gonna use constructor overloading, as we did function overloading
    Bike(int tS) : tyreSize(tS), engineSize(100){}
    Bike(): tyreSize(10), engineSize(20){}
    //now these 3 constructors will be called, as per the parameters, if only one paramter is there then 2nd, if no paremeter
    //then last, and if two paremtes then first one will be called
    // this is  known as constructor overloading, which comes under compile time polymorphism
    // this is a destructor
    ~Bike()
    {
        cout << "Destructor is being called" << endl;
    }
};
int Bike::noOfBikes = 10;
// that's how we change the value of the static variable, it belongs to class, every object will have this value.
// this :: is called scope resolution operator.
int main()
{
    Bike tvs(13, 100);
    Bike yamaha(15, 200);
    Bike royalEnfield(40, 400);
    bool flag = true;
    if (flag == true)
    {
        Bike splender(10, 80);
        cout << splender.tyreSize << " " << splender.engineSize << endl;
        // here when the object named splender goes out of the scope, then destructor is being called!
    }
    cout << tvs.tyreSize << " " << tvs.engineSize << endl;
    cout << yamaha.tyreSize << " " << yamaha.engineSize << endl;
    cout << royalEnfield.tyreSize << " " << royalEnfield.engineSize << endl;
    cout << tvs.noOfBikes << endl;
    cout << yamaha.noOfBikes << endl;

    yamaha.increaseNoOfBikes();
    cout << tvs.noOfBikes << endl;
    cout << yamaha.noOfBikes << endl;

    // every object has the same value

    // we can really take input by using constructor, and it is really better than using getters and setters
    // constructor cannot access private things, if it is inside public, and items are in

    // destructor is called when an object is out of it's scope
}