#include "linkedhashset.h"

// CR: static const fields
// static const unsigned DEFAULT_CAPACITY_OF_VECTOR = 16;
#define DEFAULT_CAPACITY_OF_VECTOR 16
#define LOADING_FACTOR 0.75

linkedhs::linkedhs() : sizeOfVector_(0), capacityOfVector_(DEFAULT_CAPACITY_OF_VECTOR), sizeOfList_(0) {
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
}

linkedhs::linkedhs(const linkedhs &other) {
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
    // CR: init list
    this->capacityOfVector_ = other.capacityOfVector_;
    this->sizeOfList_ = 0;
    this->sizeOfVector_ = 0;
    for (auto & student : other.oderOfStudents) {
      insert(student);
    }
    // auto begin = other.oderOfStudents.begin();
    // auto it = begin;
    // auto end = other.oderOfStudents.end();
    // element e;
    // while (it != end) {
    //     e = student(it->age_, it->name_);
    //     this->insert(e);
    //     it++;
    // }
}

linkedhs &linkedhs::operator=(const linkedhs &other) = default;

// CR: should be O(n) - use one of declared methods
bool linkedhs::operator==(const linkedhs &other) const {
    return this->capacityOfVector_ == other.capacityOfVector_ &&
           this->hashSet == other.hashSet && this->sizeOfList_ == other.sizeOfList_ &&
           this->sizeOfVector_ == other.sizeOfVector_;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(*this == other);
}

bool linkedhs::insert(const element &e) {
    if (contains(e))
        return false;
    // CR: use sizeOfList_ instead
    if ((sizeOfVector_ * LOADING_FACTOR) >= capacityOfVector_) {
        // CR: move elements during resize
        hashSet.resize(capacityOfVector_ * 2);
        capacityOfVector_ *= 2;
    }
    long long int hash = e.hash() % capacityOfVector_;
    if (hashSet.at(hash).empty())
        sizeOfVector_++;
    hashSet.at(hash).push_back(e);
    oderOfStudents.push_back(e);
    sizeOfList_++;
    return true;
}

// CR: should be O(1)
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
    return size() == 0;
}

bool linkedhs::contains(const element &e) const {
    return find(e) != end();
}

std::list<element>::const_iterator linkedhs::find(const element &e) const {
    long long int hash = e.hash() % capacityOfVector_;
     std::list<element> list = hashSet.at(hash);
     return std::find(list.begin(), list.end(), e);
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

std::list<student>::const_iterator linkedhs::begin() const {
  const std::list<element> elements = this->oderOfStudents;
  elements.begin();
    return oderOfStudents.begin();
}

std::list<student>::const_iterator linkedhs::end() const {
    return oderOfStudents.end();
}

