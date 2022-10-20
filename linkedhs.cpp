#include "linkedhs.h"

linkedhs::linkedhs() : head_(nullptr), last_(nullptr), listSize_(0) {}

linkedhs::~linkedhs() {
        hashSetOfStudents_.deleteTree();
        deleteList();
}

linkedhs::linkedhs(const linkedhs &other) {
    *this = linkedhs();
    node *tmpOther = other.head_;
    for (int i = 0; i < other.listSize_; i++) {
        this->insert(*tmpOther->data_);
        tmpOther = tmpOther->next_;
    }
}

linkedhs &linkedhs::operator=(const linkedhs &other) = default;

bool linkedhs::operator==(const linkedhs &other) const {
    node *tmpThis = head_;
    if (listSize_ != other.listSize_)
        return false;
    for (int i = 0; i < listSize_; i++) {
        if (!other.hashSetOfStudents_.contains(tmpThis->data_->hash_))
            return false;
        tmpThis = tmpThis->next_;
    }
    return true;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(other == *this);
}

bool linkedhs::insert(const element &e) {
    if (listSize_ != 0)
        if (contains(e))
            return false;
    hashSetOfStudents_.insert(e);
    element *currentStudent = hashSetOfStudents_.find(e.hash_);
    if (currentStudent == nullptr)
        return false;
    node *n = new node{currentStudent, nullptr, nullptr};
    if (last_ != nullptr) {
        node *tmp = last_;
        last_->next_ = n;
        last_ = n;
        last_->previous_ = tmp;
    } else {
        head_ = n;
        head_->previous_ = nullptr;
        last_ = n;
    }
    ++listSize_;
    return true;
}

bool linkedhs::remove(const element &e) {
    if (!deleteListNode(e))
        return false;
    if (!hashSetOfStudents_.remove(e.hash_))
        return false;
    return true;
}

void linkedhs::swap(linkedhs &other) {
    std::swap(*this->head_, *other.head_);
    std::swap(*this->last_, *other.last_);
    std::swap(this->hashSetOfStudents_, other.hashSetOfStudents_);
    this->listSize_ = other.listSize_;
}

size_t linkedhs::size() const {
    return listSize_;
}

bool linkedhs::empty() const {
    return hashSetOfStudents_.empty();
}

bool linkedhs::contains(const element &e) const {
    if (listSize_ == 0)
        return false;
    iterator it = find(e);
    return it.node_ != nullptr;
}

linkedhs::iterator linkedhs::find(const element &e) const {
    iterator begin(head_);
    iterator end(last_);
    iterator it = begin;
    if (listSize_ == 0) {
        it.node_ = nullptr;
        return it;
    }
    while (it != end) {
        if (e == *it.node_->data_)
            return it;
        it++;
    }
    if (e == *it.node_->data_)
        return it;
    it.node_ = nullptr;
    return it;
}

void linkedhs::printList() const {
    iterator b = this->begin();
    iterator it = b;
    iterator e = this->end();
    while (it != e) {
        std::cout << it.node_->data_->name_ << " " << it.node_->data_->age_ << std::endl;
        it++;
    }
    std::cout << it.node_->data_->name_ << " " << it.node_->data_->age_ << std::endl;
}

void linkedhs::clear() {
    deleteList();
    hashSetOfStudents_.deleteTree();
}

linkedhs::iterator linkedhs::begin() const {
    return linkedhs::iterator(head_);
}

linkedhs::iterator linkedhs::end() const {
    return linkedhs::iterator(last_);
}

//iterator

linkedhs::iterator::iterator(node *node) : node_(node) {}

element linkedhs::iterator::operator*() {
    return *node_->data_;
}

linkedhs::iterator linkedhs::iterator::operator++() {
    node_ = node_->next_;
    return iterator(node_);
}

linkedhs::iterator linkedhs::iterator::operator++(int) {
    iterator tmp(node_);
    node_ = node_->next_;
    return tmp;
}

linkedhs::iterator linkedhs::iterator::operator--() {
    node_ = node_->previous_;
    return iterator(node_);
}

linkedhs::iterator linkedhs::iterator::operator--(int) {
    iterator tmp(node_);
    node_ = node_->previous_;
    return tmp;
}

bool linkedhs::iterator::operator==(const iterator &other) const {
    return node_ == other.node_;
}

bool linkedhs::iterator::operator!=(const iterator &other) const {
    return !(*this == other);
}

void linkedhs::deleteList() {
    while (head_ != nullptr && listSize_ != 0) {
        node *next = head_->next_;
        delete head_;
        head_ = next;
        --listSize_;
    }
}

bool linkedhs::deleteListNode(const element &e) {
    if (listSize_ == 0)
        return true;
    const iterator elementToDelete = this->find(e);
    if (elementToDelete.node_->previous_ == nullptr) {
        node *tmp = elementToDelete.node_->next_;
        tmp->previous_ = nullptr;
        delete elementToDelete.node_;
        head_ = tmp;
        --listSize_;
        return true;
    }
    if (elementToDelete.node_->next_ == nullptr) {
        node *tmp = elementToDelete.node_->previous_;
        tmp->next_ = nullptr;
        delete elementToDelete.node_;
        last_ = tmp;
        --listSize_;
        return true;
    }
    if (elementToDelete.node_->next_ != nullptr && elementToDelete.node_->previous_ != nullptr) {
        node *tmpPrev = elementToDelete.node_->previous_;
        node *tmpNext = elementToDelete.node_->next_;
        tmpPrev->next_ = tmpNext;
        tmpNext->previous_ = tmpPrev;
        delete elementToDelete.node_;
        --listSize_;
        return true;
    }
    return false;
}
