from typing import List
from Person import *


class Table:
    def __init__(self, max_people: int):
        self.max_people = max_people
        self.curr_pop = 0
        self.names = []
        self.table_relationships = {}

    def addPerson(self, new_person: Person, entree, arr: List[Person] = []):
        if self.curr_pop == 0:
            for person in arr:
                self.table_relationships[person.getName()] = 0

        self.curr_pop += 1

        if entree != None:
            self.names.append(new_person.getName().title() + ", " + entree)
        else:
            self.names.append(new_person.getName().title())

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