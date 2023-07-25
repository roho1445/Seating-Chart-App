#include "Person.h"
#include "Table.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int personMaxTier(vector<Person*>& arr)
{
    int maxPerson = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i]->getTier() < arr[maxPerson]->getTier())
            maxPerson = i;
    }

    return maxPerson;
}

int main()
{
    ofstream MyExcelFile;
    MyExcelFile.open("test.csv");
    vector<Person*> Guests(4);

    for (int i = 0; i < 4; i++)
    {
        if(i == 0)
            Guests[i] = new Person("John Doe", 1, "Manager", {"enviornment", "social"}, {"Alyssa Toner"}, {});
        else if(i == 1)
            Guests[i] = new Person("Alyssa Toner", 2, "Supervisor", {"water", "social"}, {}, {});
        else if (i == 2)
            Guests[i] = new Person("Katrina Desai", 3, "Barber", {"social"}, {}, {});
        else
            Guests[i] = new Person("Billy Joel", 2, "Driver", {"social"}, {}, {});
    }

    int numberOfPeople = Guests.size();

    //Establish One way tie
    for (int i = 0; i < numberOfPeople; i++)
    {
        for(int x = 0; x < 4; x++)
        {
            if(x != i)
                Guests[i]->addPerson(*Guests[x]);
        }
    }


    //Establish 2-Way Edges
    for(int i = 0; i < numberOfPeople; i++)
    {
        for(int x = i + 1; x < 4; x++)
        {
            int initialScore = Guests[i]->getScore(Guests[x]->getName());
            Guests[i]->addScore(Guests[x]->getName(), Guests[x]->getScore(Guests[i]->getName()));
            Guests[x]->addScore(Guests[i]->getName(), initialScore);
        }
    }


    
    /*
    //Print Relationships
    for(int i = 0; i < numberOfPeople; i++)
    {
        cout<<"---------------------"<<endl;
        cout<<Guests[i]->getName()<<"'s Relationship Scores"<<endl;
        Guests[i]->printRelationships();
        cout<<endl;
    }
    */



    //Table Assignment logic
    int noTables = 2;
    vector<Table*> tableMap(noTables);

    for(int i = 0; i < noTables; i++)
    {
        tableMap[i] = new Table(2);
    }


    for(int i = 0; i < noTables; i++)
    {
        while(!tableMap[i]->isFull())
        {
            if(tableMap[i]->isEmpty())
            {
                int maxInd = personMaxTier(Guests);
                tableMap[i]->addPerson(Guests[maxInd], Guests);
                delete Guests[maxInd];
                Guests.erase(Guests.begin() + maxInd);
                
            }
            else
            {
                string personToAdd = tableMap[i]->personToAdd();
                for(int guest = 0; guest < Guests.size(); guest++)
                {
                    if(Guests[guest]->getName() == personToAdd)
                    {
                        tableMap[i]->addPerson(Guests[guest]);
                        delete Guests[guest];
                        Guests.erase(Guests.begin() + guest);
                        break;
                    }
                }
            }
        }
    }

    //Print out table assignments
    for(int i = 0; i < tableMap.size(); i++)
    {
        MyExcelFile <<"Table " << i+1 << " ----------" <<endl;
        tableMap[i]->printNames(MyExcelFile);
        MyExcelFile << endl;
    }
    
    //Delete memory allocated to tables
    for(int i = 0; i < tableMap.size(); i++)
    {
        delete tableMap[i];
    }

    //MyExcelFile << "HIIIII"<<endl;

}