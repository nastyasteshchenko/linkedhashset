#pragma once

#include "student.h"
#include <list>
#include <utility>
#include <vector>

class linkedhs {
public:
    linkedhs();

    ~linkedhs();

    //creates new linkedHashSet and assigns values from elements of other linkedHashSet to elements of new one
    // CR: what will happen to new hash set if we'll change the old one?
    linkedhs(const linkedhs &other);

    //assigns values from elements of vector other.data to elements of vector this->data
    //assigns other.elementsInOrder_ to this->oderOfStudent
    // CR: clear + copy values
    linkedhs &operator=(const linkedhs &other);

    //returns false if linkedHashSets don't have the same elements of student
    //returns true if linkedHashSets have the same elements of student
    // CR: order of elements?
    bool operator==(const linkedhs &other) const;

    bool operator!=(const linkedhs &other) const;

    //adds new element to linkedHashSet
    //returns true if inserting is successful, returns false otherwise
    // CR: successful?
    bool insert(const element &e);

    //removes the element from linkedHashSet
    //returns true if removing is successful, returns false otherwise
    // CR: same
    bool remove(const element &e);

    //swaps elements of two linked hash sets
    void swap(linkedhs &other);

    size_t size() const;

    bool empty() const;

    //returns true if element is in container
    bool contains(const element &e) const;

    //searches for the certain element in linkedHashSet
    //returns iterator that points to found element, returns end() otherwise
    std::list<element>::const_iterator find(const element &e) const;

    //clears linkedHashSet
    // CR: removes elements?
    void clear();

    //returns iterator to the first element
    // CR: insertion order?
    std::list<element>::const_iterator begin() const;

    //returns iterator that points after the last element
    std::list<element>::const_iterator end() const;

private:

    static const unsigned DEFAULT_CAPACITY_OF_VECTOR = 1;
    // CR: static constexpr?
    constexpr static const double LOADING_FACTOR = 0.75;

    size_t capacity_;
    size_t size_;

    std::list<element> elementsInOrder_;
    // CR: typedef std::list<element>::const_iterator iterator;
    std::vector<std::list<std::list<element>::const_iterator> *> data_;

    void resize(size_t capacity);

    void insertInVector(std::list<element>::const_iterator &it);

    void clearHashSet();
};

