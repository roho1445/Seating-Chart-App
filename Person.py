import collections

class Person:
    def __init__(self, name, tier = 4, job = None, themes = None, peopleLike = None, peopleDislike = None):
        self.Name = name
        self.Tier = tier
        self.Job = job
        self.Themes = themes
        self.Favorites = peopleLike
        self.Dislikes = peopleDislike
        self.Relationships = collections.defaultdict(int)
    


    def addPerson(self, newPerson):
        #Check if both people are spares
        if self.isSpare() and newPerson.isSpare():
            print("is Spare\n")
            self.Relationships[newPerson.getName()] = -10
            return
        
        #Check if one person is a spare
        if self.isSpare() or newPerson.isSpare():
            if self.isSpare():
                print(self.getName() + ' is a spare\n')
            self.Relationships[newPerson.getName()] = 0
            return
 
        score = 0
        
        #Check if newPerson is a favorite
        if newPerson.getName() in self.Favorites:
            if self.getTier() == 1:
                score += 10000
            elif self.getTier() == 2:
                score += 8000
            else:
                score += 6000
        
        #Check if newPerson is a Dislike
        if newPerson.getName() in self.Dislikes:
            if self.getTier() == 1:
                score -= 150000
            elif self.getTier() == 2:
                score -= 120000
            else:
                score -= 90000
        
        #Check for Common Themes
        score += len(set(self.Themes).intersection(set(newPerson.getThemes()))) * 5

        if newPerson.getJob() != self.Job:
            score += 5

        self.Relationships[newPerson.getName()] = score


    def printRelationships(self):
        for key in self.Relationships:
            print(key, ' -> ', self.Relationships[key])


    def getName(self):
        return self.Name
    
    def getTier(self):
        return self.Tier
    
    def getJob(self):
        return self.Job
    
    def getThemes(self):
        return self.Themes
    
    def isSpare(self):
        return self.Tier == 4
    
    def addScore(self, name, scoreAdd):
        self.Relationships[name] += scoreAdd
    
    def getScore(self, name):
        return self.Relationships[name]
    




