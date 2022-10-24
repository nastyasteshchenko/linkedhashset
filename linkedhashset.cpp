#include "linkedhashset.h"

#define DEFAULT_CAPACITY_OF_VECTOR 16
#define LOADING_FACTOR 0.75

linkedhs::linkedhs() : sizeOfVector_(0), capacityOfVector_(DEFAULT_CAPACITY_OF_VECTOR), sizeOfList_(0) {
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
}

linkedhs::linkedhs(const linkedhs &other) {
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
    this->capacityOfVector_ = other.capacityOfVector_;
    this->sizeOfList_ = 0;
    this->sizeOfVector_ = 0;
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

linkedhs &linkedhs::operator=(const linkedhs &other) = default;

bool linkedhs::operator==(const linkedhs &other) const {
    return this->capacityOfVector_ == other.capacityOfVector_ &&
           this->hashSet == other.hashSet && this->sizeOfList_ == other.sizeOfList_ &&
           this->sizeOfVector_ == other.sizeOfVector_;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(*this == other);
}

bool linkedhs::insert(const element &e) {
    if ((sizeOfVector_ * LOADING_FACTOR) >= capacityOfVector_) {
        hashSet.resize(capacityOfVector_ * 2);
        capacityOfVector_ *= 2;
    }
    if (contains(e))
        return false;
    long long int hash = e.hash() % capacityOfVector_;
    if (hashSet.at(hash).empty())
        sizeOfVector_++;
    hashSet.at(hash).push_back(e);
    oderOfStudents.push_back(e);
    sizeOfList_++;
    return true;
}

bool linkedhs::remove(const element &e) {
    long long int hash = e.hash() % capacityOfVector_;
    if (!contains(e))
        return false;
    hashSet.at(hash).remove(e);
    oderOfStudents.remove(e);
    sizeOfList_--;
    sizeOfVector_--;
    return true;
}

void linkedhs::swap(linkedhs &other) {
    std::swap(this->hashSet, other.hashSet);
    std::swap(this->oderOfStudents, other.oderOfStudents);
    std::swap(this->capacityOfVector_, other.capacityOfVector_);
    std::swap(this->sizeOfList_, other.sizeOfList_);
    std::swap(this->sizeOfVector_, other.sizeOfVector_);
}

size_t linkedhs::size() const {
    return sizeOfList_;
}

bool linkedhs::empty() const {
    return sizeOfList_ == 0;
}

bool linkedhs::contains(const element &e) const {
    if (sizeOfList_ == 0)
        return false;
    long long int hash = e.hash() % capacityOfVector_;
    auto begin = hashSet.at(hash).begin();
    auto end = hashSet.at(hash).end();
    auto it = begin;
    while (it != end) {
        if (it->age_ == e.age_ && it->name_ == e.name_)
            return true;
        it++;
    }
    return false;
}

std::_List_iterator<student> linkedhs::find(const element &e) {
    long long int hash = e.hash() % capacityOfVector_;
    auto begin = hashSet.at(hash).begin();
    auto end = hashSet.at(hash).end();
    auto it = begin;
    while (it != end) {
        if (it->age_ == e.age_ && it->name_ == e.name_)
            return it;
        it++;
    }
    return oderOfStudents.end();
}

void linkedhs::clear() {
    for (size_t i = 0; i < sizeOfList_; i++) {
        hashSet.vector::at(i).clear();
    }
    oderOfStudents.clear();
    sizeOfList_ = 0;
    sizeOfVector_ = 0;
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
}

std::_List_const_iterator<student> linkedhs::begin() const {
    return oderOfStudents.begin();
}

std::_List_const_iterator<student> linkedhs::end() const {
    return oderOfStudents.end();
}

