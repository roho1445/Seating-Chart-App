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
private:
    std::vector<std::string> Favorites;
    std::vector<std::string> Dislikes;
    std::vector<std::string> Themes;
    std::unordered_map<std::string, int> Relationships;
    std::string Name;
    std::string Job;
    int Tier;

    bool spare = false;
    
};

