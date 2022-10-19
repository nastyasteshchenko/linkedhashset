#include "student.h"

student::student() : age_(0), hash_(0) {
    name_ = '\0';
}

student::student(const unsigned age, std::string name) : age_(age), name_(std::move(name)), hash_(0) {}

bool student::operator==(const student &other) const {
    return other.age_ == age_ && other.name_ == name_;
}

bool student::operator!=(const student &other) const {
    return !(other == *this);
}

long long int student::hash() const {
    long long int h = 0;
    int p = 31;
    for (char c: name_) {
        h += (c - 'a' + 1) * p;
        p *= 31;
    }
    h = p * h + age_;
    return std::abs(h);
}
