#include "Person.h"
#include <iostream>
#include <algorithm>
using namespace std;

Person::Person(std::string name, int tier, std::string job, const std::vector<std::string>& themes, const std::vector<std::string>& peopleLike, const std::vector<std::string>& peopleDislike) :
    Tier(tier), Name(name), Job(job)
{
    for(int i = 0; i < peopleLike.size(); i++)
    {
        Favorites.push_back(peopleLike[i]);
    }

    for(int i = 0; i < peopleDislike.size(); i++)
    {
        Dislikes.push_back(peopleDislike[i]);
    }

    for(int i = 0; i < themes.size(); i++)
    {
        Themes.push_back(themes[i]);
    }

    sort(Favorites.begin(), Favorites.end());
    sort(Dislikes.begin(), Dislikes.end());
    sort(Themes.begin(), Themes.end());

}


void Person::addPerson(Person &newPerson)
{
    if(newPerson.isSpare())
    {
        Relationships.insert({newPerson.getName(), 0});
        return;
    }
    
    int score = 0;

    //Check if newPerson is liked
    if (find(Favorites.begin(), Favorites.end(), newPerson.getName()) != Favorites.end())
    {
        if(this->getTier() == 1)
            score += 1000;
        else if(this->getTier() == 2)
            score += 800;
        else
            score += 600;
    }

    //Check if newPerson is disliked
    if (find(Dislikes.begin(), Dislikes.end(), newPerson.getName()) != Dislikes.end())
    {
        if(this->getTier() == 1)
            score -= 1500;
        else if(this->getTier() == 2)
            score -= 1300;
        else
            score -= 1100;
    }
    
    
    //Check if any themes are Common
    vector<string> common (Themes.size() + newPerson.getThemes().size());
    vector<string>::iterator end = set_intersection(Themes.begin(), Themes.end(), newPerson.getThemes().begin(), newPerson.getThemes().end(), common.begin());
    score += (end - common.begin())*5;


    //Check if jobs are common
    if(newPerson.getJob() != Job)
        score += 5;

    Relationships.insert({newPerson.getName(), score});
}

void Person::printRelationships()
{
    for (auto i : Relationships)
        cout << i.first << "    " << i.second << endl;
}