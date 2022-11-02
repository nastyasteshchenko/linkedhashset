#pragma once

#include "student.h"
#include <list>
#include <vector>

class linkedhs {
public:

    //assigns the value 0 to sizeOfList_, the value DEFAULT_CAPACITY_OF_VECTOR to capacityOfVector_
    //makes resize of hashSet to DEFAULT_CAPACITY_OF_VECTOR elements and fills hashSet nullptr value
    linkedhs();

    //clears memory of HashSet
    ~linkedhs();

    //creates new linkedHashSet and assigns values from elements of other linkedHashSet to elements of new one
    linkedhs(const linkedhs &other);

    //assigns values from elements of vector other.hashSet to elements of vector this->hashSet
    //assigns other.oderOfStudents to this->oderOfStudent
    linkedhs &operator=(const linkedhs &other);

    //returns false if linkedHashSets don't have the same elements of students
    //returns true if linkedHashSets have the same elements of students
    bool operator==(const linkedhs &other) const;

    //returns false if linkedHashSets have the same elements of students
    //returns true if linkedHashSets don't have the same elements of students
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
    std::list<student>::const_iterator find(const element &e) const;

    //clears linkedHashSet
    void clear();

    //returns iterator on the first element of oderOfStudents list
    std::list<student>::const_iterator begin() const;

    //returns iterator on the after last element of oderOfStudents list
    std::list<student>::const_iterator end() const;

private:
    // CR: entry
    struct elementOfHashSet {
        // CR: storing student here and in history (reference somewhere)
        element student;
        // CR: order_it_
        std::list<element>::const_iterator pointerToElemInOderList;
    };

    static const unsigned DEFAULT_CAPACITY_OF_VECTOR = 1;
    static constexpr const double LOADING_FACTOR = 0.75;
    // CR: capacity_
    size_t capacityOfVector_;
    // CR: size_
    size_t sizeOfList_;
    // CR: oderOfStudents_, hashSet_
    // CR: elements_in_order_
    std::list<element> oderOfStudents;
    // CR: data_
    std::vector<std::list<elementOfHashSet> *> hashSet;

    //resizes vector; makes the elements move relative to the new capacity
    void resize(size_t capacity);

    //clear memory of hashSet
    void clearHashSet();
};

