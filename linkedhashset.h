#pragma once

#include "student.h"
#include <list>
#include <utility>
#include <vector>

class linkedhs {
public:

    //assigns the value 0 to size_, the value DEFAULT_CAPACITY_OF_VECTOR to capacity_
    //makes resize of data to DEFAULT_CAPACITY_OF_VECTOR elements and fills data nullptr value
    linkedhs();

    //clears memory of HashSet
    ~linkedhs();

    //creates new linkedHashSet and assigns values from elements of other linkedHashSet to elements of new one
    linkedhs(const linkedhs &other);

    //assigns values from elements of vector other.data to elements of vector this->data
    //assigns other.elementsInOrder_ to this->oderOfStudent
    linkedhs &operator=(const linkedhs &other);

    //returns false if linkedHashSets don't have the same elements of student
    //returns true if linkedHashSets have the same elements of student
    bool operator==(const linkedhs &other) const;

    //returns false if linkedHashSets have the same elements of student
    //returns true if linkedHashSets don't have the same elements of student
    bool operator!=(const linkedhs &other) const;

    //adds new element to linkedHashSet
    //returns true if inserting is successful, returns false otherwise
    bool insert(const element &e);

    //removes the element from linkedHashSet
    //returns true if removing is successful, returns false otherwise
    bool remove(const element &e);

    //swaps linkedHashSets
    void swap(linkedhs &other);

    //returns size of linkedHashSet
    size_t size() const;

    //checks if linkedHashSet is empty
    //returns true if linkedHashSet is empty, returns false otherwise
    bool empty() const;

    //checks if the element contains in linkedHashSet
    //returns true if element with certain hash exists, returns false otherwise
    bool contains(const element &e) const;

    //looks for the certain element in linkedHashSet
    //returns the certain element in linkedHashSet if it exists, returns end() otherwise
    std::list<element>::const_iterator find(const element &e) const;

    //clears linkedHashSet
    void clear();

    //returns iterator on the first element of elementsInOrder_ list
    std::list<element>::const_iterator begin() const;

    //returns iterator on the after last element of elementsInOrder_ list
    std::list<element>::const_iterator end() const;

private:

    static const unsigned DEFAULT_CAPACITY_OF_VECTOR = 1;
    constexpr static const double LOADING_FACTOR = 0.75;

    size_t capacity_;
    size_t size_;

    std::list<element> elementsInOrder_;
    std::vector<std::list< std::list<element>::const_iterator> *> data_;

    //resizes vector; makes the elements move relative to the new capacity
    void resize(size_t capacity);

    //adds elements in new vector of linkedHashSet according to new capacity
    void insertInVector(std::list<element>::const_iterator &it);

    //clear memory of data_
    void clearHashSet();
};

