#include "hashtree.h"

hashTree::hashTree() {
    root_ = nullptr;
    size_ = 0;
}

void hashTree::insert(const element &e) {
    long long int hash = e.hash();
    while (contains(hash))
        hash++;
    e.hash_ = hash;
    auto *node = new hashTree::node{nullptr, nullptr, e};
    if (root_ == nullptr) {
        root_ = node;
        ++size_;
    } else {
        hashTree::node *current = root_;
        while (current) {
            if (hash < current->data_.hash_ && current->left_ == nullptr) {
                current->left_ = node;
                ++size_;
                break;
            } else if (hash > current->data_.hash_ && current->right_ == nullptr) {
                current->right_ = node;
                ++size_;
                break;
            }
            if (hash < current->data_.hash_)
                current = current->left_;
            else if (hash > current->data_.hash_)
                current = current->right_;
        }
    }
}

bool hashTree::contains(const long long int hash) const {
    return find(hash) != nullptr;
}

student *hashTree::find(const long long int hash) const {
    hashTree::node *current = root_;
    while (current && current->data_.hash_ != hash)
        if (hash < current->data_.hash_) {
            current = current->left_;
        } else if (hash > current->data_.hash_) {
            current = current->right_;
        }
    if (current == nullptr)
        return nullptr;
    return &current->data_;
}

bool hashTree::empty() const {
    return size_ == 0;
}

bool hashTree::remove(const long long hash) {
    node *current = root_;
    node *parent = nullptr;
    while (current && current->data_.hash_ != hash) {
        parent = current;
        if (current->data_.hash_ > hash)
            current = current->left_;
        else current = current->right_;
    }
    if (!current)
        return false;
    if (parent->left_ == nullptr && parent->right_ == nullptr) {
        --size_;
        delete current;
        return true;
    }
    if (current->left_ == nullptr) {
        if (parent->left_ == current)
            parent->left_ = current->right_;
        if (parent->right_ == current)
            parent->right_ = current->right_;
        --size_;
        delete current;
        return true;
    }
    if (current->right_ == nullptr) {
        if (parent->left_ == current)
            parent->left_ = current->left_;
        if (parent->right_ == current)
            parent->right_ = current->left_;
        delete current;
        return true;
    }
    node *replace = current->right_;
    while (replace->left_)
        replace = replace->left_;
    student replace_data = replace->data_;
    long long int replace_hash = replace->data_.hash_;
    remove(replace_hash);
    current->data_.hash_ = replace_hash;
    current->data_ = replace_data;
    return true;
}

void hashTree::clear(node *current) {
    if (current) {
        clear(current->left_);
        clear(current->right_);
        delete current;
    }
}

void hashTree::deleteTree() {
    clear(root_);
}





