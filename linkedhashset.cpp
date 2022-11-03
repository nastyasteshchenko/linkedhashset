#include "linkedhashset.h"
#include <iostream>

linkedhs::linkedhs() : capacity_(DEFAULT_CAPACITY_OF_VECTOR), size_(0) {
    data_.resize(DEFAULT_CAPACITY_OF_VECTOR);
}

linkedhs::~linkedhs() {
    clearHashSet();
}

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
    return *this;
}

bool linkedhs::operator==(const linkedhs &other) const {
    if (size_ != other.size_)
        return false;
    for (const auto &it: other.elementsInOrder_) {
        if (!contains(it))
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
    long long int hash = e.hash() % capacity_;
    if (data_.at(hash) == nullptr)
        data_.at(hash) = new std::list<std::list<element>::const_iterator>;
    data_.at(hash)->push_back(elementsInOrder_.insert(elementsInOrder_.end(), e));
    size_++;
    return true;
}

bool linkedhs::remove(const element &e) {
    auto it = find(e);
    if (it == end())
        return false;
    long long int hash = e.hash() % capacity_;
    data_.at(hash)->remove(it);
    elementsInOrder_.erase(it);
    if (data_.at(hash)->empty()) {
        delete data_.at(hash);
        data_.at(hash) = nullptr;
    }
    size_--;
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

std::list<element>::const_iterator linkedhs::find(const element &e) const {
    long long int hash = e.hash() % capacity_;
    if (data_.at(hash) == nullptr)
        return end();
    for (auto &it: *data_.at(hash)) {
        if (e == *it)
            return it;
    }
    return end();
}

void linkedhs::clear() {
    clearHashSet();
    elementsInOrder_.clear();
    size_ = 0;
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
        }
    }
}