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
            self.Relationships[newPerson.getName()] = -10
            return
        
        #Check if one person is a spare
        if self.isSpare or newPerson.isSpare():    
            self.Relationships[newPerson.getName()] = 0
            return
 
        score = 0
        
        #Check if newPerson is a favorite
        if newPerson.getName() in self.Favorites:
            if self.getTier() == 1:
                score += 1000
            elif self.getTier() == 2:
                score += 800
            else:
                score += 600
        
        #Check if newPerson is a Dislike
        if newPerson.getName() in self.Dislikes:
            if self.getTier() == 1:
                score -= 1500
            elif self.getTier() == 2:
                score -= 1200
            else:
                score -= 900
        
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
        return self.Job == None
    
    def addScore(self, name, scoreAdd):
        self.Relationships[name] += scoreAdd
    
    def getScore(self, name):
        return self.Relationships[name]
    




