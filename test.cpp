#include "Person.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;



int main()
{
    Person *Guests [4];
    vector<Person*> firstTier;
    vector<Person*> secondTier;
    vector<Person*> thirdTier;

    cout<<"first output"<<endl;

    for (int i = 0; i < 4; i++)
    {
        if(i == 0)
            Guests[i] = new Person("John Doe", 1, "Manager", {"enviornment", "social"}, {"Alyssa Toner", "Emma Watson"}, {"Merryl Streep"});
        else if(i == 1)
            Guests[i] = new Person("Alyssa Toner", 2, "Supervisor", {"water", "social"}, {"Emma Watson"}, {"John Doe"});
        else if (i == 2)
            Guests[i] = new Person("Bill Barber", 3, "Barber", {"social"}, {}, {});
        else
            Guests[i] = new Person("Billy Joel", 2, "Driver", {"social"}, {}, {});
    }


    cout<<"people created"<<endl;

    //Establish One way tie
    for (int i = 0; i < 4; i++)
    {
        for(int x = 0; x < 4; x++)
        {
            if(x != i)
                Guests[i]->addPerson(*Guests[x]);
        }
    }

    cout<<"One-Way Tie"<<endl;

    //Establish 2-Way Edges
    for(int i = 0; i < 4; i++)
    {
        cout<<"In first loop"<<endl;
        for(int x = i + 1; x < 4; x++)
        {
            cout<<"In 2nd loop"<<endl;
            int initialScore = Guests[i]->getScore(Guests[x]->getName());
            cout<<"Initial score set"<<endl;
            Guests[i]->addScore(Guests[x]->getName(), Guests[x]->getScore(Guests[i]->getName()));
            cout<<"One way score added"<<endl;
            Guests[x]->addScore(Guests[i]->getName(), initialScore);
            cout<<"two way score added"<<endl;
        }
    }

    cout<<"Two-Way Tie"<<endl;
    
    //Print Relationships
    for(int i = 0; i < 4; i++)
    {
        cout<<"---------------------"<<endl;
        cout<<"Name is: "<<Guests[i]->getName()<<endl;
        Guests[i]->printRelationships();
        cout<<endl;
    }



    /*
    Person *Tables[2][2];

    for(int tables = 0; tables < 2; tables++)
    {
        for(int seats = 0; seats < 2; seats++)
        {
            //Adding "Table Captain"
            if (seats = 0)
            {
                for(int i = 0; i < 4; i++)
                {
                    if (Guests[i] != nullptr)
                    {
                        Tables[tables][seats] = Guests[i];
                    }
                }
            }
        }
    }
    */
}