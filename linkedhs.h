#ifndef LAB1_LINKEDHASHSET_H
#define LAB1_LINKEDHASHSET_H

#include "student.h"
#include "hashtree.h"

class linkedhs {
    struct node {
        element *data_{};
        node *next_{}, *previous_{};
    };
public:
    class iterator {
    public:

        explicit iterator(node *node);

        element operator*();

        iterator operator++();

        iterator operator++(int);

        iterator operator--();

        iterator operator--(int);

        bool operator==(const iterator &other) const;

        bool operator!=(const iterator &other) const;

    private:
        friend class linkedhs;

        node *node_;
    };

    linkedhs();

    ~linkedhs();

    linkedhs(const linkedhs &other);

    linkedhs &operator=(const linkedhs &other);

    bool operator==(const linkedhs &other) const;

    bool operator!=(const linkedhs &other) const;

    bool insert(const element &e); //adds new element to the list
    //returns true if inserting is successful, returns false otherwise

    bool remove(const element &e); //removes the element from the list
    //returns true if removing is successful, returns false otherwise

    void swap(linkedhs &other) const; //swaps the lists

    size_t size() const; //returns size of the list

    bool empty() const; //checks if list is empty
    //returns true if list is empty, returns false otherwise

    bool contains(const element &e) const; //checks if the element contains in the list
    //returns true if element with certain hash exists, returns false otherwise

    iterator find(const element &e) const; //looks for the certain element in the list
    //returns the certain element in the list

    void printList(); //prints the list

    void clear(); //clears the list

    iterator begin();

    iterator end();

private:
    class hashTree hashSetOfStudents_;

    node *head_;
    node *last_;
    node *parent;
    int listSize_;

    void deleteList(); //deletes the list

    bool deleteListNode(const element &e); //deletes the node of the list
    //returns true if deleting is successful, returns false otherwise

};


#endif //LAB1_LINKEDHASHSET_H
