#include "linkedhs.h"

linkedhs::linkedhs() : listSize_(0), head_(nullptr), last_(nullptr), parent(nullptr) {}

linkedhs::~linkedhs() {
    deleteList();
    hashSetOfStudents_.deleteTree();
}

linkedhs::linkedhs(const linkedhs &other) {
    node *tmpParent = nullptr;
    node *tmpOther = other.head_;
    for (int i = 0; i < other.listSize_; i++) {
        node *n = new node{tmpOther->data_, nullptr, nullptr};
        if (tmpParent != nullptr) {
            node *tmp = tmpParent;
            tmpParent->next_ = n;
            tmpParent = n;
            last_ = n;
            tmpParent->previous_ = tmp;
        } else {
            head_ = n;
            head_->previous_ = nullptr;
            last_ = n;
            tmpParent = n;
        }
        tmpOther = tmpOther->next_;
    }
    listSize_ = other.listSize_;
    parent = other.parent;
}

linkedhs &linkedhs::operator=(const linkedhs &other) = default;

bool linkedhs::operator==(const linkedhs &other) const {
    node *tmpThis = head_;
    node *tmpOther = other.head_;
    if (listSize_ != other.listSize_)
        return false;
    for (int i = 0; i < listSize_; i++) {
        if (tmpThis->data_ != tmpOther->data_)
            return false;
        tmpThis = tmpThis->next_;
        tmpOther = tmpOther->next_;
    }
    return head_ == other.head_;
}

bool linkedhs::operator!=(const linkedhs &other) const {
    return !(other == *this);
}

bool linkedhs::insert(const element &e) {
    if (size() != 0)
        if (contains(e))
            return false;
    hashSetOfStudents_.insert(e);
    element *currentStudent = hashSetOfStudents_.find(e.hash_);
    if (currentStudent == nullptr)
        return false;
    node *n = new node{currentStudent, nullptr, nullptr};
    if (parent != nullptr) {
        node *tmp = parent;
        parent->next_ = n;
        parent = n;
        last_ = n;
        parent->previous_ = tmp;
    } else {
        head_ = n;
        head_->previous_ = nullptr;
        last_ = n;
        parent = n;
    }
    ++listSize_;
    return true;
}

bool linkedhs::remove(const element &e) {
    if (!deleteListNode(e))
        return false;
    if (!hashSetOfStudents_.remove(e.hash_))
        return false;
    --listSize_;
    return true;
}

void linkedhs::swap(linkedhs &other) const {
    const linkedhs &tmp(other);
    other = *this;
    other = tmp;
}

size_t linkedhs::size() const {
    return listSize_;
}

bool linkedhs::empty() const {
    return hashSetOfStudents_.empty();
}

bool linkedhs::contains(const element &e) const {
    iterator it = find(e);
    return it.node_ != nullptr;
}

linkedhs::iterator linkedhs::find(const element &e) const {
    iterator begin(head_);
    iterator end(last_);
    iterator it = begin;
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

void linkedhs::printList() {
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

linkedhs::iterator linkedhs::begin() {
    return linkedhs::iterator(head_);
}

linkedhs::iterator linkedhs::end() {
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
    while (head_ != nullptr) {
        node *next = head_->next_;
        delete head_;
        head_ = next;
    }
}

bool linkedhs::deleteListNode(const element &e) {
    const iterator elementToDelete = this->find(e);
    if (elementToDelete.node_->previous_ == nullptr) {
        node *tmp = elementToDelete.node_->next_;
        tmp->previous_ = nullptr;
        delete elementToDelete.node_;
        head_ = tmp;
        return true;
    }
    if (elementToDelete.node_->next_ == nullptr) {
        node *tmp = elementToDelete.node_->previous_;
        tmp->next_ = nullptr;
        delete elementToDelete.node_;
        last_ = tmp;
        return true;
    }
    if (elementToDelete.node_->next_ != nullptr && elementToDelete.node_->previous_ != nullptr) {
        node *tmpPrev = elementToDelete.node_->previous_;
        node *tmpNext = elementToDelete.node_->next_;
        tmpPrev->next_ = tmpNext;
        tmpNext->previous_ = tmpPrev;
        delete elementToDelete.node_;
    }
    return false;
}
