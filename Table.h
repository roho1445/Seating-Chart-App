#pragma once
#include "Person.h"
#include <string>
#include <vector>
#include <unordered_map>

class Table
{
    public:
        Table(int maxPeople);
        void addPerson(Person newPerson);
        void printNames();
        bool isFull() {return MaxPeople == currPop;}
        
    private:
        int MaxPeople;
        int currPop;
        std::unordered_map<std::string, int> TableRelationships;

};