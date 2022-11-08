#include "linkedhashset.h"
#include <iostream>

linkedhs::linkedhs() : capacity_(DEFAULT_CAPACITY_OF_VECTOR), size_(0) {
    data_.resize(capacity_);
}

linkedhs::~linkedhs() {
    clearHashSet(&data_);
}

linkedhs::linkedhs(const linkedhs &other) : capacity_(DEFAULT_CAPACITY_OF_VECTOR), size_(0) {
    data_.resize(capacity_);
    for (const auto &it: other.elementsInOrder_) {
        insert(it);
    }
}

linkedhs &linkedhs::operator=(const linkedhs &other) {
    if (*this == other) {
        return *this;
    }
    clear();
    for (const auto &it: other.elementsInOrder_) {
        insert(it);
    }
    return *this;
}

bool linkedhs::operator==(const linkedhs &other) const {
    if (size_ != other.size_) {
        return false;
    }
    for (const auto &it: other.elementsInOrder_) {
        if (!contains(it)) {
            return false;
        }
    }
    return true;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(*this == other);
}

bool linkedhs::insert(const element &e) {
    if (contains(e)) {
        return false;
    }
    if ((double) size_ / capacity_ >= LOADING_FACTOR) {
        resize();
    }
    long long int hash = e.hash() % capacity_;
    if (data_[hash] == nullptr) {
        data_[hash] = new std::list<orderIterator>;
    }
    data_[hash]->push_back(elementsInOrder_.insert(elementsInOrder_.end(), e));
    size_++;
    return true;
}

bool linkedhs::remove(const element &e) {
    auto it = find(e);
    if (it == end()) {
        return false;
    }
    long long int hash = e.hash() % capacity_;
    data_[hash]->remove(it);
    elementsInOrder_.erase(it);
    if (data_[hash]->empty()) {
        delete data_[hash];
        data_[hash] = nullptr;
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
    return find(e) != end();
}

linkedhs::orderIterator linkedhs::find(const element &e) const {
    if (size_ == 0) {
        return end();
    }
    long long int hash = e.hash() % capacity_;
    if (data_[hash] == nullptr) {
        return end();
    }
    for (auto &it: *data_[hash]) {
        if (e == *it) {
            return it;
        }
    }
    return end();
}

void linkedhs::clear() {
    clearHashSet(&data_);
    elementsInOrder_.clear();
    size_ = 0;
}

linkedhs::orderIterator linkedhs::begin() const {
    return elementsInOrder_.begin();
}

linkedhs::orderIterator linkedhs::end() const {
    return elementsInOrder_.end();
}

void linkedhs::resize() {
    std::vector<std::list<orderIterator> *> tmpVector = std::move(data_);
    data_ = std::vector<std::list<orderIterator> *>(capacity_ * 2);
    size_t countSize = size_;
    for (size_t i = 0; i < capacity_ && countSize != 0; i++) {
        if (tmpVector[i] != nullptr) {
            for (auto &it: *tmpVector[i]) {
                long long int hash = (*it).hash() % (capacity_ * 2);
                if (data_[hash] == nullptr) {
                    data_[hash] = new std::list<orderIterator>;
                }
                data_[hash]->push_back(it);
                --countSize;
            }
        }
    }
    capacity_ *= 2;
    clearHashSet(&tmpVector);
}

void linkedhs::clearHashSet(std::vector<std::list<orderIterator> *> *data) const {
    size_t size = size_;
    for (size_t i = 0; i < data->capacity() && size != 0; i++) {
        if (data->at(i) != nullptr) {
            size -= data->at(i)->size();
            delete data->at(i);
            data->at(i) = nullptr;
        }
    }
}
