#include "linkedhashset.h"
#include <iostream>

linkedhs::linkedhs() : capacityOfVector_(DEFAULT_CAPACITY_OF_VECTOR), sizeOfList_(0) {
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
    // CR: maybe fill is redundant?
    std::fill(hashSet.begin(), hashSet.end(), nullptr);
}

linkedhs::~linkedhs() {
    clearHashSet();
}

linkedhs::linkedhs(const linkedhs &other) : capacityOfVector_(DEFAULT_CAPACITY_OF_VECTOR), sizeOfList_(0) {
    hashSet.resize(capacityOfVector_);
    for (const auto &it: other)
        insert(it);
}

linkedhs &linkedhs::operator=(const linkedhs &other) {
    // CR: lhs = lhs;
    // CR: 1. clear old data 2. insert data from other
    this->capacityOfVector_ = other.capacityOfVector_;
    for (size_t i = 0; i < other.capacityOfVector_; i++)
        if (other.hashSet.at(i) != nullptr)
            this->hashSet.at(i) = other.hashSet.at(i);
    this->oderOfStudents = other.oderOfStudents;
    this->sizeOfList_ = other.sizeOfList_;
    return *this;
}

bool linkedhs::operator==(const linkedhs &other) const {
    if (sizeOfList_ != other.sizeOfList_)
        return false;
    for (const auto &it: other)
        if (!this->contains(it))
            return false;
    return true;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(*this == other);
}

bool linkedhs::insert(const element &e) {
    if (contains(e))
        return false;
    if ((double) sizeOfList_ / capacityOfVector_ >= LOADING_FACTOR) {
        capacityOfVector_ *= 2;
        this->resize(capacityOfVector_);
    }
    long long int hash = e.hash() % capacityOfVector_;
    if (hashSet.at(hash) == nullptr) {
        auto elemOfHashSet = new std::list<elementOfHashSet>;
        hashSet.at(hash) = elemOfHashSet;
    }
    // CR: list::insert()
    oderOfStudents.push_back(e);
    elementOfHashSet tmp = {e, --oderOfStudents.end()};
    hashSet.at(hash)->push_back(tmp);
    sizeOfList_++;
    return true;
}

bool linkedhs::remove(const element &e) {
    if (!contains(e))
        return false;
    long long int hash = e.hash() % capacityOfVector_;
    assert(hashSet.at(hash) != nullptr);
    for (auto it = hashSet.at(hash)->begin(); it != hashSet.at(hash)->end(); it++)
        if (it->student == e) {
            oderOfStudents.erase(it->pointerToElemInOderList);
            hashSet.at(hash)->erase(it);
            if (hashSet.at(hash)->empty()) {
                delete hashSet.at(hash);
                hashSet.at(hash)= nullptr;
            }
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
    if (sizeOfList_ == 0)
        return false;
    return find(e) != end();
}


// CR: declare custom iterator, return it from find(); use it inside insert and remove
// class iterator {
//   public:
//   element operator*() {
//     return eohs_.student;
//   }
//   private:
//     elementOfHashSet eohs_;
// };

std::list<element>::const_iterator linkedhs::find(const element &e) const {
    long long int hash = e.hash() % capacityOfVector_;
    if (hashSet.at(hash) == nullptr)
        return end();
    for (elementOfHashSet &it: *hashSet.at(hash))
        if (e == it.student)
            return it.pointerToElemInOderList;
    return end();
}

void linkedhs::clear() {
    clearHashSet();
    oderOfStudents.clear();
    sizeOfList_ = 0;
}

std::list<student>::const_iterator linkedhs::begin() const {
    return oderOfStudents.begin();
}

std::list<student>::const_iterator linkedhs::end() const {
    return oderOfStudents.end();
}

void linkedhs::resize(size_t capacity) {
    std::vector<std::list<elementOfHashSet> *> tmpVector(capacity);
    // CR:
    // tmp = hashSet;
    // hashSet = std::vector(capacity);
    // orderOfStudents.clear();
    // for (auto it : tmp) {
    //   this.insert(it);
    // }
    for (size_t i = 0; i < hashSet.capacity(); i++) {
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
    }
    this->clearHashSet();
    this->hashSet = tmpVector;
}

void linkedhs::clearHashSet() {
    for (size_t i = 0; i < hashSet.capacity(); i++) {
    // CR:
    // sizeOfList_ -= hashSet.at(i).size();
    // delete list
    // if (sizeOfList_ == 0) break;
        if (hashSet.at(i) != nullptr) {
            delete hashSet.at(i);
            hashSet.at(i)= nullptr;
        }
    }
}