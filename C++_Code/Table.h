#pragma once
#include "Person.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>

class Table
{
    public:
        Table(int maxPeople):MaxPeople(maxPeople){}
        void addPerson(Person* newPerson, const std::vector<Person*>& arr);
        std::string personToAdd();
        void printNames(std::ofstream& MyExcelFile);
        bool isFull() {return MaxPeople == currPop;}
        bool isEmpty() {return currPop == 0;}
        
    private:
        int MaxPeople;
        int currPop = 0;
        std::vector<std::string> names;
        std::unordered_map<std::string, int> TableRelationships;

};

void Table::addPerson(Person* newPerson, const std::vector<Person*>& arr = {})
{
    if(currPop == 0)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            TableRelationships.insert({arr[i]->getName(), 0});
        }
    }

    currPop++;
    names.push_back(newPerson->getName());
    TableRelationships.erase(newPerson->getName());


/*
    for(auto person : TableRelationships)
    {
        person.second += newPerson->Relationships[person.first];
    }
    */
    
    for (auto person : newPerson->Relationships)
    {
        if(TableRelationships.find(person.first) != TableRelationships.end())
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

void Table::printNames(std::ofstream& MyExcelFile)
{
    for(auto p : names)
    {
        MyExcelFile<<p<<std::endl;
    }
}