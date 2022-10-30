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
<<<<<<< HEAD

    //assigns values from elements of vector other.hashSet to elements of vector this->hashSet
    //assigns other.oderOfStudents to this->oderOfStudent
=======
    // CR: comments
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
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

<<<<<<< HEAD
    //looks for the certain element in linkedHashSet
    //returns the certain element in linkedHashSet if it exists, returns end() otherwise
=======
    //looks for the certain element in the list
    //returns the certain element in the list if it exists, returns end() otherwise
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
    std::list<student>::const_iterator find(const element &e) const;

    //clears linkedHashSet
    void clear();

<<<<<<< HEAD
    //returns iterator on the first element of oderOfStudents list
    std::list<student>::const_iterator begin() const;

    //returns iterator on the after last element of oderOfStudents list
    std::list<student>::const_iterator end() const;

private:
    struct elementOfHashSet {
        element student;
        std::list<element>::const_iterator pointerToElemInOderList;
    };
    static const unsigned DEFAULT_CAPACITY_OF_VECTOR = 1;
    constexpr static const double LOADING_FACTOR = 0.75;
    size_t capacityOfVector_;
    size_t sizeOfList_;
=======
    std::list<student>::const_iterator begin() const;

    std::list<student>::const_iterator end() const;

private:
    // CR: remove
    size_t sizeOfVector_;
    int capacityOfVector_;
    size_t sizeOfList_;
    // CR: use pointers to lists instead of lists by themselves
    std::vector<std::list<element>> hashSet;
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
    std::list<element> oderOfStudents;
    std::vector<std::list<elementOfHashSet> *> hashSet;

    //resizes vector; makes the elements move relative to the new capacity
    void resize(size_t capacity);

    //clear memory of hashSet
    void clearHashSet();
};

