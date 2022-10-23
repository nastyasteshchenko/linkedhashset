#include "linkedhashset.h"
#include <array>
#include <list>

linkedhs::linkedhs() : capacityOfArray_(CAPACITY_OF_ARRAY), sizeOfList(0) {}

linkedhs::linkedhs(const linkedhs &other) {
    this->capacityOfArray_ = other.capacityOfArray_;
    auto begin = other.oderOfStudents.begin();
    auto it = begin;
    auto end = other.oderOfStudents.end();
    element e;
    while (it != end) {
        std::cout << it->name_ << std::endl;
        e = student(it->age_, it->name_);
        this->insert(e);
        it++;
    }
    this->sizeOfList = other.sizeOfList;
}

bool linkedhs::insert(const element &e) {
    if (contains(e))
        return false;
    long long int hash = e.hash() % capacityOfArray_;
    hashSet[hash].push_back(e);
    oderOfStudents.push_back(e);
    sizeOfList++;
    return true;
}

bool linkedhs::contains(const element &e) const {
    if (sizeOfList == 0)
        return false;
    long long int hash = e.hash() % capacityOfArray_;
    auto begin = hashSet[hash].begin();
    auto end = hashSet[hash].end();
    auto it = begin;
    while (it != end) {
        if (it->age_ == e.age_ && it->name_ == e.name_)
            return true;
        it++;
    }
    return false;
}

bool linkedhs::remove(const element &e) {
    long long int hash = e.hash() % capacityOfArray_;
    if (!contains(e))
        return false;
    hashSet[hash].remove(e);
    oderOfStudents.remove(e);
    sizeOfList--;
    return true;
}

size_t linkedhs::size() const {
    return sizeOfList;
}

void linkedhs::swap(linkedhs &other) {
    std::swap(this->hashSet, other.hashSet);
    std::swap(this->oderOfStudents, other.oderOfStudents);
    std::swap(this->capacityOfArray_, other.capacityOfArray_);
    std::swap(this->sizeOfList, other.sizeOfList);
}

bool linkedhs::empty() const {
    return sizeOfList == 0;
}

void linkedhs::clear() { //дописать
    for (size_t i = 0; i < sizeOfList; i++) {
        hashSet[i].clear();
    }
    oderOfStudents.clear();
    sizeOfList = 0;
}

auto linkedhs::begin() const {
    return oderOfStudents.begin();
}

auto linkedhs::end() const {
    return oderOfStudents.end();
}

bool linkedhs::operator==(const linkedhs &other) const {
    return this->capacityOfArray_ == other.capacityOfArray_ &&
           this->hashSet == other.hashSet && this->sizeOfList == other.sizeOfList;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(*this == other);
}

linkedhs &linkedhs::operator=(const linkedhs &other) = default;

void linkedhs::printList() {
    auto begin = oderOfStudents.begin();
    auto end = oderOfStudents.end();
    auto it = begin;
    while (it != end) {
        std::cout << it->name_ << " " << it->age_ << std::endl;
        it++;
    }

}
