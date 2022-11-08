#pragma once

#include <iostream>

struct student {

    //assigns the value 0 to age_ and assigns the value '\0' to name_
    student();

    student(unsigned age, std::string name);

    //returns true if ages and names equal
    //returns false if ages or names are not equal
    bool operator==(const student &other) const;

    bool operator!=(const student &other) const;

    //counts hash for the student
    //returns value of hash
    long long int hash() const;

    unsigned age_;
    std::string name_;

};

typedef student element;
