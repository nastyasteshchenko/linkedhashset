#include "linkedhashset.h"

#define DEFAULT_CAPACITY_OF_VECTOR 16
#define LOADING_FACTOR 0.75

linkedhs::linkedhs() : sizeOfVector(0), capacityOfVector_(DEFAULT_CAPACITY_OF_VECTOR), sizeOfList(0) {
    hashSetVect.resize(DEFAULT_CAPACITY_OF_VECTOR);
}

linkedhs::linkedhs(const linkedhs &other) {
    hashSetVect.resize(DEFAULT_CAPACITY_OF_VECTOR);
    this->capacityOfVector_ = other.capacityOfVector_;
    this->sizeOfList = 0;
    this->sizeOfVector = 0;
    auto begin = other.oderOfStudents.begin();
    auto it = begin;
    auto end = other.oderOfStudents.end();
    element e;
    while (it != end) {
        e = student(it->age_, it->name_);
        this->insert(e);
        it++;
    }
}

bool linkedhs::insert(const element &e) {
    if ((sizeOfVector * LOADING_FACTOR) >= capacityOfVector_) {
        hashSetVect.resize(capacityOfVector_ * 2);
        capacityOfVector_ *= 2;
    }
    if (contains(e))
        return false;
    long long int hash = e.hash() % capacityOfVector_;
    if (hashSetVect.at(hash).empty())
        sizeOfVector++;
    hashSetVect.vector::at(hash).push_back(e);
    oderOfStudents.push_back(e);
    sizeOfList++;
    return true;
}

bool linkedhs::contains(const element &e) const {
    if (sizeOfList == 0)
        return false;
    long long int hash = e.hash() % capacityOfVector_;
    auto begin = hashSetVect.at(hash).begin();
    auto end = hashSetVect.at(hash).end();
    auto it = begin;
    while (it != end) {
        if (it->age_ == e.age_ && it->name_ == e.name_)
            return true;
        it++;
    }
    return false;
}

bool linkedhs::remove(const element &e) {
    long long int hash = e.hash() % capacityOfVector_;
    if (!contains(e))
        return false;
    hashSetVect.at(hash).remove(e);
    oderOfStudents.remove(e);
    sizeOfList--;
    return true;
}

size_t linkedhs::size() const {
    return sizeOfList;
}

void linkedhs::swap(linkedhs &other) {
    std::swap(this->hashSetVect, other.hashSetVect);
    std::swap(this->oderOfStudents, other.oderOfStudents);
    std::swap(this->capacityOfVector_, other.capacityOfVector_);
    std::swap(this->sizeOfList, other.sizeOfList);
}

bool linkedhs::empty() const {
    return sizeOfList == 0;
}

void linkedhs::clear() {
    for (size_t i = 0; i < sizeOfList; i++) {
        hashSetVect.vector::at(i).clear();
    }
    oderOfStudents.clear();
    sizeOfList = 0;
    hashSetVect.resize(DEFAULT_CAPACITY_OF_VECTOR);
}

auto linkedhs::begin() const {
    return oderOfStudents.begin();
}

auto linkedhs::end() const {
    return oderOfStudents.end();
}

bool linkedhs::operator==(const linkedhs &other) const {
    return this->capacityOfVector_ == other.capacityOfVector_ &&
           this->hashSetVect == other.hashSetVect && this->sizeOfList == other.sizeOfList;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(*this == other);
}

linkedhs &linkedhs::operator=(const linkedhs &other) = default;
