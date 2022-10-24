#pragma once

#include "student.h"
#include <list>
#include <vector>

class linkedhs {
public:

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
    //returns the certain element in the list if it exists, returns end() otherwise
    std::_List_iterator<student> find(const element &e);

    //clears the list
    void clear();

    std::_List_const_iterator<student> begin() const;

    std::_List_const_iterator<student> end() const;

private:
    size_t sizeOfVector_;
    int capacityOfVector_;
    size_t sizeOfList_;
    std::vector<std::list<element>> hashSet;
    std::list<element> oderOfStudents;
};

