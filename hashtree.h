#ifndef ORIGLAB1_HASHTREE_H
#define ORIGLAB1_HASHTREE_H

#include "hashtree.h"
#include "student.h"

class hashTree {
    struct node {
        node *left_, *right_;
        element data_;
    };

    hashTree();

    void insert(const element &e); //adds new node to the tree and returns hash of added node
    //returns true if inserting is successful, returns false otherwise

    bool contains(const long long int hash) const; //checks if element with certain hash exists
    //returns true if element with certain hash exists, returns false otherwise

    element *find(const long long int hash) const; //looks for the element which has certain hash
    //returns pointer to the element with certain hash

    bool empty() const; //checks if hashTree is empty
    //returns true if tree is empty, returns false otherwise

    bool remove(long long hash); //removes the element this certain hash
    //returns true if removing is successful, returns false otherwise

    friend class linkedhs;

    node *root_;
    int size_;

    void clear(node *current); //clears the tree starting from the certain node

    void deleteTree(); //clears the whole tree
};

#endif //ORIGLAB1_HASHTREE_H
