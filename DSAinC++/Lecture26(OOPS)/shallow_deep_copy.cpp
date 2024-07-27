/**
 


Shallow :

it is a kind of copy,

say we have object 1 = 10,20(we have some values given to object 1)
so there will be a memory block in the memory allocated to object 1
now, if I make another object, say object 2
then object 2 will get his data from the same memory block allocated to object 1
and then I say object 2 = object 1
and now if I try to print the values of object 2, I will get the same value as of object 1

but now, if i change the values of object 1, say 40,003

and now print object 2, then the values of object 2 will also be get changed.

This kind of copy is known as "Shallow Copy";
changing the original object, will change the value of the second object too!



Deep Copy : 
in deep copy,
if I copy object 1 to some other object,
then both will get different memory block in the memory, 
hence, if I change one, there will be no effect on the other object!



Copy Constructor :
It is used to copy the objects

as normal constructor is used to initialise the object, and for object creation
this one is used for coying one object into another!

copy constructor creates a deep copy always

say, 
Bike new = old;
here old bike is being copied to new one!, here this is used using copy constructor
and this is deep copy!

another method to do so!
Bike new(old);

now, how to write the copy constructor

say
Bike( Bike b);

here, this is pass by value,(Bike b) is pass by value

Now, here, we know that, whenever there is a pass by value, then always, compiler makes a copy of the passed parameter
and then work on the copied parameter,
here too, a new copy will get generated and that will go to the constructor named Bike(remember, constructor do not have names)
and then it will check the parameter, which will again call the constructor, and this process will continue for infinite time
Hence, there is an infinite loop!


So, due to this reason, whenever I pass a paremeter inside a copy constructor, I pass it by reference and not by value
and the load of creating a deep copy is on copy constructor and not on the compiler!

Hence, the following method is far better to avoid infinite loop
Bike (Bike &b); this is pass by reference



Static Members:
static keyword is used with a variable to make it's memory static, once the static variable is declared, it's memory cannot be changed!


*/