'''
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
'''

from typing import List
from Person import *


class Table:
    def __init__(self, max_people: int, showJob):
        self.max_people = max_people
        self.curr_pop = 0
        self.names = []
        self.table_relationships = {}
        self.distributingGuests = False
        self.showJobs = showJob

    def addPerson(self, new_person: Person, entree, arr: List[Person] = []):
        if entree == "Adding Initial Guest696969":
            self.distributingGuests = True

        if self.curr_pop == 0 or (self.containsOnlyEmpties() and self.distributingGuests and entree != "Adding Initial Guest696969"):
            for person in arr:
                self.table_relationships[person.getName()] = 0

        self.curr_pop += 1
        name = new_person.getName().title()

        if self.showJobs and entree != "Adding Initial Guest696969":
            if new_person.getJob() != None:
                name += ", " + new_person.getJob()
            elif entree != None:
                name += ", "


        if entree != None and entree != "Adding Initial Guest696969":
            name += ", " + entree
        
        self.names.append(name)

        if entree != "Adding Initial Guest696969":
            self.table_relationships.pop(new_person.getName(), None)

            for person, value in new_person.Relationships.items():
                if person in self.table_relationships:
                    self.table_relationships[person] += value

    def personToAdd(self):
        return max(self.table_relationships, key=self.table_relationships.get)
    
    def printNames(self, r, c, sheet, tableNo):
        for name in self.names:
            sheet.cell(row = r, column = c).value = name
            sheet.cell(row = r, column = c+1).value = tableNo
            r += 1
        return r

    def isFull(self):
        return self.max_people == self.curr_pop

    def isEmpty(self):
        return self.curr_pop == 0
    
    def containsOnlyEmpties(self):
        return self.names[self.curr_pop - 1][:10].lower() == "empty seat"