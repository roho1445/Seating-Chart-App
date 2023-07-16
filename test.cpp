#include "Person.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{
    Person *Guests [4];

    for (int i = 0; i < 4; i++)
    {
        if(i = 0)
            Guests[i] = new Person("John Doe", 1, "Manager", {"enviornment", "social"}, {"Alyssa Toner", "Emma Watson"}, {"Merryl Streep"});
        else if(i = 1)
            Guests[i] = new Person("Alyssa Toner", 2, "Supervisor", {"water", "social"}, {"Emma Watson"}, {"John Doe"});
        else if (i = 2)
            Guests[i] = new Person("Bill Barber", 3, "Barber", {"social"}, {}, {});
        else
            Guests[i] = new Person("Billy Joel", 2, "Driver", {"social"}, {}, {});
    }   
    
    
    
    Person John("John Doe", 1, "Manager", {"enviornment", "social"}, {"Alyssa Toner", "Emma Watson"}, {"Merryl Streep"});
    Person Alyssa("Alyssa Toner", 2, "Supervisor", {"water", "social"}, {"Emma Watson"}, {"John Doe"});
    Person Spare1(1);

    John.addPerson(Alyssa);
    John.addPerson(Spare1);

    Alyssa.addPerson(John);
    Alyssa.addPerson(Spare1);

    cout << "John's Relationships" << endl;
    John.printRelationships();

    cout << endl;

    cout << "Alyssa's Relationships" << endl;
    Alyssa.printRelationships();

}