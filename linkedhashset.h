#pragma once

#include "student.h"
#include <list>
#include <utility>
#include <vector>

class linkedhs {
public:
    linkedhs();

    ~linkedhs();

    //creates new linked hash set and assigns values from elements of other linked hash set to elements of new one
    //if old linked hash set is changed new one will stay the same
    linkedhs(const linkedhs &other);

    //if linked hash sets are equivalent nothing changes
    //if linked hash sets aren't equivalent the first linked hash set is cleared and values are copied into it from another
    linkedhs &operator=(const linkedhs &other);

    //returns false if linkedHashSets don't have the same elements of student
    //returns true if linkedHashSets have the same elements of student regardless of order
    bool operator==(const linkedhs &other) const;

    bool operator!=(const linkedhs &other) const;

    //adds new element to linkedHashSet
    //returns true if the element is not in the linked hash set, returns false otherwise
    bool insert(const element &e);

    //removes the element from linkedHashSet
    //returns true if the element is in the linked hash set, returns false otherwise
    bool remove(const element &e);

    //swaps elements of two linked hash sets
    void swap(linkedhs &other);

    size_t size() const;

    bool empty() const;

    //returns true if element is in container
    bool contains(const element &e) const;

    //searches for the certain element in linked hash set
    //returns iterator that points to found element, returns end() otherwise
    std::list<element>::const_iterator find(const element &e) const;

    //removes all elements from linked hash set
    void clear();

    //returns iterator to the first added element
    std::list<element>::const_iterator begin() const;

    //returns iterator that points after the last added element
    std::list<element>::const_iterator end() const;

private:

    typedef std::list<element>::const_iterator orderIterator;

    static constexpr unsigned DEFAULT_CAPACITY_OF_VECTOR = 1;
    static constexpr double LOADING_FACTOR = 0.75;

    size_t capacity_;
    size_t size_;

    std::list<element> elementsInOrder_;
    std::vector<std::list<orderIterator> *> data_;

    void resize();

    void clearHashSet(std::vector<std::list<orderIterator> *> *data) const;
};

