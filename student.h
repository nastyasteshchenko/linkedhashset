#ifndef LAB1_STUDENT_H
#define LAB1_STUDENT_H

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
private:
    friend class linkedhs;
    friend class hashTree;
    mutable long long int hash_;
};

typedef student element;

#endif //LAB1_STUDENT_H
