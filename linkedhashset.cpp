#include "linkedhashset.h"
#include <iostream>

<<<<<<< HEAD
linkedhs::linkedhs() : capacity_(DEFAULT_CAPACITY_OF_VECTOR), size_(0) {
    data_.resize(DEFAULT_CAPACITY_OF_VECTOR);
=======
linkedhs::linkedhs() : capacityOfVector_(DEFAULT_CAPACITY_OF_VECTOR), sizeOfList_(0) {
    hashSet.resize(DEFAULT_CAPACITY_OF_VECTOR);
    // CR: maybe fill is redundant?
    std::fill(hashSet.begin(), hashSet.end(), nullptr);
>>>>>>> bf2905e8a5e1e99fb726daeb0180e63d06e0a9e0
}

linkedhs::~linkedhs() {
    clearHashSet();
}

<<<<<<< HEAD
linkedhs::linkedhs(const linkedhs &other) : capacity_(other.capacity_), size_(0) {
    data_.resize(capacity_);
    for (const auto &it: other.elementsInOrder_) {
        insert(it);
    }
}

linkedhs &linkedhs::operator=(const linkedhs &other) {
    if (*this == other)
        return *this;
    clear();
    data_.resize(capacity_);
    for (const auto &it: other.elementsInOrder_) {
        insert(it);
    }
=======
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
>>>>>>> bf2905e8a5e1e99fb726daeb0180e63d06e0a9e0
    return *this;
}

bool linkedhs::operator==(const linkedhs &other) const {
    if (size_ != other.size_)
        return false;
<<<<<<< HEAD
    for (const auto &it: other.elementsInOrder_) {
        if (!contains(it))
=======
    for (const auto &it: other)
        if (!this->contains(it))
>>>>>>> bf2905e8a5e1e99fb726daeb0180e63d06e0a9e0
            return false;
    }
    return true;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(*this == other);
}

bool linkedhs::insert(const element &e) {
    if (contains(e))
        return false;
    if ((double) size_ / (double) capacity_ >= LOADING_FACTOR) {
        capacity_ *= 2;
        resize(capacity_);
    }
<<<<<<< HEAD
    long long int hash = e.hash() % capacity_;
    if (data_.at(hash) == nullptr)
        data_.at(hash) = new std::list<std::list<element>::const_iterator>;
    data_.at(hash)->push_back(elementsInOrder_.insert(elementsInOrder_.end(), e));
    size_++;
=======
    // CR: list::insert()
    oderOfStudents.push_back(e);
    elementOfHashSet tmp = {e, --oderOfStudents.end()};
    hashSet.at(hash)->push_back(tmp);
    sizeOfList_++;
>>>>>>> bf2905e8a5e1e99fb726daeb0180e63d06e0a9e0
    return true;
}

bool linkedhs::remove(const element &e) {
    auto it = find(e);
    if (it == end())
        return false;
<<<<<<< HEAD
    long long int hash = e.hash() % capacity_;
    data_.at(hash)->remove(it);
    elementsInOrder_.erase(it);
    if (data_.at(hash)->empty()) {
        delete data_.at(hash);
        data_.at(hash) = nullptr;
    }
    size_--;
=======
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
>>>>>>> bf2905e8a5e1e99fb726daeb0180e63d06e0a9e0
    return true;
}

void linkedhs::swap(linkedhs &other) {
    std::swap(data_, other.data_);
    std::swap(elementsInOrder_, other.elementsInOrder_);
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
}

size_t linkedhs::size() const {
    return size_;
}

bool linkedhs::empty() const {
    return size() == 0;
}

bool linkedhs::contains(const element &e) const {
    if (size_ == 0)
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
    long long int hash = e.hash() % capacity_;
    if (data_.at(hash) == nullptr)
        return end();
<<<<<<< HEAD
    for (auto &it: *data_.at(hash)) {
        if (e == *it)
            return it;
    }
=======
    for (elementOfHashSet &it: *hashSet.at(hash))
        if (e == it.student)
            return it.pointerToElemInOderList;
>>>>>>> bf2905e8a5e1e99fb726daeb0180e63d06e0a9e0
    return end();
}

void linkedhs::clear() {
    clearHashSet();
<<<<<<< HEAD
    elementsInOrder_.clear();
    size_ = 0;
=======
    oderOfStudents.clear();
    sizeOfList_ = 0;
>>>>>>> bf2905e8a5e1e99fb726daeb0180e63d06e0a9e0
}

std::list<element>::const_iterator linkedhs::begin() const {
    return elementsInOrder_.begin();
}

std::list<element>::const_iterator linkedhs::end() const {
    return elementsInOrder_.end();
}

void linkedhs::insertInVector(std::list<element>::const_iterator &it) {
    long long int hash = (*it).hash() % capacity_;
    if (data_.at(hash) == nullptr)
        data_.at(hash) = new std::list<std::list<element>::const_iterator>;
    data_.at(hash)->push_back(it);
}

void linkedhs::resize(size_t capacity) {
<<<<<<< HEAD
    std::vector<std::list<std::list<element>::const_iterator> *> tmpVector = data_;
    data_ = std::vector<std::list<std::list<element>::const_iterator> *>(capacity);
    for (size_t i = 0; i < capacity_ / 2; i++) {
        if (tmpVector.at(i) != nullptr)
            for (auto &it: *tmpVector.at(i)) {
                insertInVector(it);
            }
    }
    size_t countSize = size_;
    for (size_t i = 0; i < tmpVector.capacity() && countSize != 0; i++) {
        if (tmpVector.at(i) != nullptr) {
            countSize -= tmpVector.at(i)->size();
            delete tmpVector.at(i);
        }
    }
}

void linkedhs::clearHashSet() {
    for (size_t i = 0; i < data_.capacity(); i++) {
        if (size_ == 0) break;
        if (data_.at(i) != nullptr) {
            size_ -= data_.at(i)->size();
            delete data_.at(i);
            data_.at(i) = nullptr;
=======
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
>>>>>>> bf2905e8a5e1e99fb726daeb0180e63d06e0a9e0
        }
    }
}