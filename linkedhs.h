#ifndef LAB1_LINKEDHASHSET_H
#define LAB1_LINKEDHASHSET_H

#include "student.h"
#include "hashtree.h"

class linkedhs {
public:
    struct node {
        element *data_{};
        node *next_{}, *previous_{};
    };

    node *head_;
    node *last_;

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

    linkedhs(); //assigns nullptr to pointers to nodes head_, last_, parent_ присваивает nullptr, assigns 0 to listSize_

    ~linkedhs(); //clears memory

    linkedhs(const linkedhs &other);

    linkedhs &operator=(const linkedhs &other);

    bool operator==(const linkedhs &other) const;

    bool operator!=(const linkedhs &other) const;

    bool insert(const element &e); //adds new element to the list
    //returns true if inserting is successful, returns false otherwise

    bool remove(const element &e); //removes the element from the list
    //returns true if removing is successful, returns false otherwise

    void swap(linkedhs &other); //swaps the lists

    size_t size() const; //returns size of the list

    bool empty() const; //checks if list is empty
    //returns true if list is empty, returns false otherwise

    bool contains(const element &e) const; //checks if the element contains in the list
    //returns true if element with certain hash exists, returns false otherwise

    iterator find(const element &e) const; //looks for the certain element in the list
    //returns the certain element in the list

    void clear(); //clears the list

    iterator begin() const;

    iterator end() const;

private:
    class hashTree hashSetOfStudents_;

    int listSize_;

    void deleteList(); //deletes the list

    bool deleteListNode(const element &e); //deletes the node of the list
    //returns true if deleting is successful, returns false otherwise

    void printList() const; //prints the list
};


#endif //LAB1_LINKEDHASHSET_H
