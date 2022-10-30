#pragma once

#include <iostream>

struct student {

    //assigns the value 0 to age_ and assigns the value '\0' to name_
    student();

    //assigns value of age to  age_ and assigns value of name to name_
    student(unsigned age, std::string name);

    //returns true if fields age_ and name_ are equal
    //returns false if fields age_ or name_ are not equal
    bool operator==(const student &other) const;

    //returns true if fields age_ or name_ are equal
    //returns false if fields age_ and name_ are not equal
    bool operator!=(const student &other) const;

    //counts hash for the student
    //returns value of hash
    long long int hash() const;

    unsigned age_;
    std::string name_;

};

typedef student element;
