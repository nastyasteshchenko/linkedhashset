#pragma once
#include <iostream>

struct student {
    student();

    student(unsigned age, std::string name);

    bool operator==(const student &other) const;

    bool operator!=(const student &other) const;

    //counts hash for the student
    //returns value of hash
    long long int hash() const;

    unsigned age_;
    std::string name_;

};

typedef student element;
