#pragma once
#include <iostream>

struct student {
    student();

    student(unsigned age, std::string name);

    bool operator==(const student &other) const;

    bool operator!=(const student &other) const;

    long long int hash() const; //counts hash for the student
    //returns value of hash

    unsigned age_;
    std::string name_;

};

typedef student element;
