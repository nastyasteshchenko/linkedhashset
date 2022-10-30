#include "linkedhashset.h"
#include <iostream>

<<<<<<< HEAD
linkedhs::linkedhs() : capacityOfVector_(DEFAULT_CAPACITY_OF_VECTOR), sizeOfList_(0) {
=======
// CR: static const fields
// static const unsigned DEFAULT_CAPACITY_OF_VECTOR = 16;
#define DEFAULT_CAPACITY_OF_VECTOR 16
#define LOADING_FACTOR 0.75

linkedhs::linkedhs() : sizeOfVector_(0), capacityOfVector_(DEFAULT_CAPACITY_OF_VECTOR), sizeOfList_(0) {
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
    std::fill(hashSet.begin(), hashSet.end(), nullptr);
}

<<<<<<< HEAD
linkedhs::~linkedhs() {
    clearHashSet();
}

linkedhs::linkedhs(const linkedhs &other) : capacityOfVector_(other.capacityOfVector_), sizeOfList_(0) {
    hashSet.resize(capacityOfVector_);
    for (const auto &it: other)
        insert(student(it.age_, it.name_));
=======
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
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
}

linkedhs &linkedhs::operator=(const linkedhs &other) {
    this->capacityOfVector_ = other.capacityOfVector_;
    for (size_t i = 0; i < other.capacityOfVector_; i++)
        if (other.hashSet.at(i) != nullptr)
            this->hashSet.at(i) = other.hashSet.at(i);
    this->oderOfStudents = other.oderOfStudents;
    this->sizeOfList_ = other.sizeOfList_;
    return *this;
}

// CR: should be O(n) - use one of declared methods
bool linkedhs::operator==(const linkedhs &other) const {
    if (sizeOfList_ != other.sizeOfList_)
        return false;
    for (const auto &it: other)
        if (!this->contains(student(it.age_, it.name_)))
            return false;
    return true;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(*this == other);
}

bool linkedhs::insert(const element &e) {
    if (contains(e))
        return false;
<<<<<<< HEAD
    if ((double) sizeOfList_ / capacityOfVector_ >= LOADING_FACTOR){
        capacityOfVector_ *= 2;
        this->resize(capacityOfVector_);
=======
    // CR: use sizeOfList_ instead
    if ((sizeOfVector_ * LOADING_FACTOR) >= capacityOfVector_) {
        // CR: move elements during resize
        hashSet.resize(capacityOfVector_ * 2);
        capacityOfVector_ *= 2;
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
    }
    long long int hash = e.hash() % capacityOfVector_;
    if (hashSet.at(hash) == nullptr) {
        auto elemOfHashSet = new std::list<elementOfHashSet>;
        hashSet.at(hash) = elemOfHashSet;
    }
    oderOfStudents.push_back(e);
    elementOfHashSet tmp = {e, --oderOfStudents.end()};
    hashSet.at(hash)->push_back(tmp);
    sizeOfList_++;
    return true;
}

// CR: should be O(1)
bool linkedhs::remove(const element &e) {
    if (!contains(e))
        return false;
    long long int hash = e.hash() % capacityOfVector_;
    if (hashSet.at(hash) != nullptr)
        for (auto it = hashSet.at(hash)->begin(); it != hashSet.at(hash)->end(); it++)
            if (it->student == e) {
                oderOfStudents.erase(it->pointerToElemInOderList);
                hashSet.at(hash)->erase(it);
                break;
            }
    sizeOfList_--;
    return true;
}

void linkedhs::swap(linkedhs &other) {
    std::swap(this->hashSet, other.hashSet);
    std::swap(this->oderOfStudents, other.oderOfStudents);
    std::swap(this->capacityOfVector_, other.capacityOfVector_);
    std::swap(this->sizeOfList_, other.sizeOfList_);
}

size_t linkedhs::size() const {
    return sizeOfList_;
}

bool linkedhs::empty() const {
    return size() == 0;
}

bool linkedhs::contains(const element &e) const {
<<<<<<< HEAD
    if (sizeOfList_ == 0)
        return false;
=======
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
    return find(e) != end();
}

std::list<element>::const_iterator linkedhs::find(const element &e) const {
    long long int hash = e.hash() % capacityOfVector_;
<<<<<<< HEAD
    if (hashSet.at(hash) == nullptr)
        return end();
    for (auto &it: *hashSet.at(hash))
        if (e == it.student)
            return it.pointerToElemInOderList;
    return end();
=======
     std::list<element> list = hashSet.at(hash);
     return std::find(list.begin(), list.end(), e);
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
}

void linkedhs::clear() {
    clearHashSet();
    oderOfStudents.clear();
    sizeOfList_ = 0;
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
    std::fill(hashSet.begin(), hashSet.end(), nullptr);
}

std::list<student>::const_iterator linkedhs::begin() const {
<<<<<<< HEAD
=======
  const std::list<element> elements = this->oderOfStudents;
  elements.begin();
>>>>>>> a81f21a9071292090b824e9afc9330e17dd45e68
    return oderOfStudents.begin();
}

std::list<student>::const_iterator linkedhs::end() const {
    return oderOfStudents.end();
}

void linkedhs::resize(size_t capacity) {
    std::vector<std::list<elementOfHashSet> *> tmpVector(capacity);
    std::fill(tmpVector.begin(), tmpVector.end(), nullptr);
    for (size_t i = 0; i < capacity / 2; i++)
        if (hashSet.at(i) != nullptr)
            for (auto &it: *hashSet.at(i)) {
                long long int hash = it.student.hash() % capacityOfVector_;
                if (tmpVector.at(hash) == nullptr) {
                    auto elemOfHashSet = new std::list<elementOfHashSet>;
                    tmpVector.at(hash) = elemOfHashSet;
                }
                elementOfHashSet tmp = {it.student, it.pointerToElemInOderList};
                tmpVector.at(hash)->push_back(tmp);
            }
    this->clearHashSet();
    this->hashSet = tmpVector;
}

void linkedhs::clearHashSet() {
    for (size_t i = 0; i < sizeOfList_; i++)
        if (hashSet.at(i) != nullptr)
            delete hashSet.at(i);
}