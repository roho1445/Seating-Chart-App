/*
*****************************************************************************************************
Copyright (c) Rohith Venkatesh.                                                           
All Rights Reserved.      


Created by Rohith Venkatesh
UCLA EXTERNAL AFFAIRS INTERN SUMMER 2023

App created for UCLA External Affars and the Events team at the UCLA College

Contact:
rvenkatesh2025@ucla.edu
https://www.linkedin.com/in/rohithvenkatesh/
*****************************************************************************************************
*/


#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class Person
{
public:
    Person(std::string name, int tier, std::string job, const std::vector<std::string>& themes, 
        const std::vector<std::string>& peopleLike, const std::vector<std::string>& peopleDislike);
    Person(int spareNum) : Name("Spare Seat " + std::to_string(spareNum)), spare(true){}
    void addPerson(Person &newPerson);
    void printRelationships();
    std::string getName() {return Name;}
    int getTier() {return Tier;}
    std::string getJob() {return Job;}
    std::vector<std::string>& getThemes() {return Themes;}
    bool isSpare() {return spare;}
    void addScore(std::string name, int scoreAdd) {Relationships.at(name) += scoreAdd;}
    int getScore(std::string name) {return Relationships.at(name);}
    std::unordered_map<std::string, int> Relationships;
private:
    std::vector<std::string> Favorites;
    std::vector<std::string> Dislikes;
    std::vector<std::string> Themes;
    std::string Name;
    std::string Job;
    int Tier;

    bool spare = false;
    
};

