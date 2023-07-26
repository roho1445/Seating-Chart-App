from typing import List
from Person import *


class Table:
    def __init__(self, max_people: int):
        self.max_people = max_people
        self.curr_pop = 0
        self.names = []
        self.table_relationships = {}

    def addPerson(self, new_person: Person, arr: List[Person] = []):
        if self.curr_pop == 0:
            for person in arr:
                self.table_relationships[person.getName()] = 0

        self.curr_pop += 1
        self.names.append(new_person.getName())
        self.table_relationships.pop(new_person.getName(), None)

        for person, value in new_person.Relationships.items():
            if person in self.table_relationships:
                self.table_relationships[person] += value

    def personToAdd(self):
        return max(self.table_relationships, key=self.table_relationships.get)
    
    def printNames(self, r, c, sheet):
        for name in self.names:
            #print(name.title())
            sheet.cell(row = r, column = c).value = name.title()
            r += 1
        return r

    def isFull(self):
        return self.max_people == self.curr_pop

    def isEmpty(self):
        return self.curr_pop == 0