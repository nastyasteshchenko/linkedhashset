#pragma once
#ifndef RELINKEDHASHSET_LINKEDHASHSET_H
#define RELINKEDHASHSET_LINKEDHASHSET_H

#include "student.h"
#include <array>
#include <list>

#define CAPACITY_OF_ARRAY 255

class linkedhs {
public:

    //assigns nullptr to pointers to nodes head_, last_, parent_ присваивает nullptr, assigns 0 to listSize_
    linkedhs();

    linkedhs(const linkedhs &other);

    linkedhs &operator=(const linkedhs &other);

    bool operator==(const linkedhs &other) const;

    bool operator!=(const linkedhs &other) const;

    //adds new element to the list
    //returns true if inserting is successful, returns false otherwise
    bool insert(const element &e);

    //removes the element from the list
    //returns true if removing is successful, returns false otherwise
    bool remove(const element &e);

    //swaps the lists
    void swap(linkedhs &other);

    //returns size of the list
    size_t size() const;

    //checks if list is empty
    //returns true if list is empty, returns false otherwise
    bool empty() const;

    //checks if the element contains in the list
    //returns true if element with certain hash exists, returns false otherwise
    bool contains(const element &e) const;

    //looks for the certain element in the list
    //returns the certain element in the list

    //clears the list
    void clear();

    auto begin() const;

    auto end() const;

    void printList(); //prints the list

private:
    friend class iterator;

    int capacityOfArray_;
    size_t sizeOfList;
    std::array<std::list<element>, CAPACITY_OF_ARRAY> hashSet;
    std::list<element> oderOfStudents;
};

#endif //RELINKEDHASHSET_LINKEDHASHSET_H
