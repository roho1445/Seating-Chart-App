#pragma once
#include "Person.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

class Table
{
    public:
        Table(int maxPeople):MaxPeople(maxPeople){}
        void addPerson(Person* newPerson);
        std::string personToAdd();
        void printNames();
        bool isFull() {return MaxPeople == currPop;}
        
    private:
        int MaxPeople;
        int currPop = 0;
        std::vector<std::string> names;
        std::unordered_map<std::string, int> TableRelationships;

};

void Table::addPerson(Person* newPerson)
{
    if(currPop == 0)
    {
        TableRelationships = newPerson->Relationships;
        names.push_back(newPerson->getName());
        currPop++;
        return;
    }
    
    currPop++;
    names.push_back(newPerson->getName());
    TableRelationships.erase(newPerson->getName());
    

    for (auto person : newPerson->Relationships)
    {
        TableRelationships[person.first] += person.second;
    }

}


std::string Table::personToAdd()
{
    std::unordered_map<std::string, int>::iterator it = TableRelationships.begin();
    int maxScore = it->second;
    std::string maxName = it->first;

    it++;

    while (it != TableRelationships.end())
    {
        if(it->second > maxScore)
        {
            maxScore = it->second;
            maxName = it->first;
        }
        it++;
    }

    return maxName;
}

void Table::printNames()
{
    for(auto p : names)
    {
        std::cout<<p<<std::endl;
    }
}