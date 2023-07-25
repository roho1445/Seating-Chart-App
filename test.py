from Person import *
from Table import *

def personMaxTier(arr):
    maxPerson = 0
    for i in range(1, len(arr)):
        if arr[i].getTier() < arr[maxPerson].getTier():
            maxPerson = i
    return maxPerson

if __name__ == "__main__":
    Guests = []
    Guests.append(Person("John Doe", 1, "Manager", ["enviornment", "social"], ["Alyssa Toner"], []))
    Guests.append(Person("Alyssa Toner", 2, "Supervisor", ["water", "social"], [], []))
    Guests.append(Person("Katrina Desai", 3, "Barber", ["social"], [], []))
    Guests.append(Person("Billy Joel", 2, "Driver", ["social"], [], []))
    
    numberOfPeople = len(Guests)
    

    #Establishing One-Way Tie
    for i in range(numberOfPeople):
        for x in range(4):
            if x != i:
                Guests[i].addPerson(Guests[x])
    
    #Establishing Two-Way Tie
    for i in range(numberOfPeople):
        for x in range(i + 1, 4):
            initialScore = Guests[i].getScore(Guests[x].getName())

    #Table Organizational Logic
    noTables = 2
    tableMap = [Table(2) for _ in range(noTables)]

    for table in tableMap:
        while not table.isFull():
            if table.isEmpty():
                maxInd = personMaxTier(Guests)
                table.addPerson(Guests[maxInd], Guests)
                del Guests[maxInd]
            else:
                personToAdd = table.personToAdd()
                for guest in range(len(Guests)):
                    if Guests[guest].getName() == personToAdd:
                        table.addPerson(Guests[guest])
                        del Guests[guest]
                        break



    #Outputting Tables with People sitting there
    for i in range(len(tableMap)):
        print("Table " + str(i+1) + " ----------")
        tableMap[i].printNames()
        print("\n")

