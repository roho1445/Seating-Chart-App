#include "Person.h"
#include "Table.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;



int main()
{
    Person *Guests [4];

    for (int i = 0; i < 4; i++)
    {
        if(i == 0)
            Guests[i] = new Person("John Doe", 1, "Manager", {"enviornment", "social"}, {"Alyssa Toner", "Emma Watson"}, {"Merryl Streep"});
        else if(i == 1)
            Guests[i] = new Person("Alyssa Toner", 2, "Supervisor", {"water", "social"}, {"Emma Watson"}, {"John Doe"});
        else if (i == 2)
            Guests[i] = new Person("Katrina Desai", 3, "Barber", {"social"}, {}, {});
        else
            Guests[i] = new Person("Billy Joel", 2, "Driver", {"social"}, {}, {});
    }

    //Establish One way tie
    for (int i = 0; i < 4; i++)
    {
        for(int x = 0; x < 4; x++)
        {
            if(x != i)
                Guests[i]->addPerson(*Guests[x]);
        }
    }


    //Establish 2-Way Edges
    for(int i = 0; i < 4; i++)
    {
        cout<<"In first loop"<<endl;
        for(int x = i + 1; x < 4; x++)
        {
            int initialScore = Guests[i]->getScore(Guests[x]->getName());
            Guests[i]->addScore(Guests[x]->getName(), Guests[x]->getScore(Guests[i]->getName()));
            Guests[x]->addScore(Guests[i]->getName(), initialScore);
        }
    }


    
    
    //Print Relationships
    for(int i = 0; i < 4; i++)
    {
        cout<<"---------------------"<<endl;
        cout<<Guests[i]->getName()<<"'s Relationship Scores"<<endl;
        Guests[i]->printRelationships();
        cout<<endl;
    }


    Table tab1(2);
    Table tab2(2);
    int ppl = 4;
    

    tab1.addPerson(Guests[0]);
    cout<<"Table 1 ----------"<<endl;
    cout<<Guests[0]->getName()<<endl;
    cout<<tab1.personToAdd()<<endl;

    cout<<endl;

    cout<<"Table 2 ----------"<<endl;
    cout<<Guests[1]->getName()<<endl;
    cout<<"Katrina Desai"<<endl;




}