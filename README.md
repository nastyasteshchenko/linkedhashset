# LAB1 Linkedhashset
Implement a linkedhash set based on a given interface. The algorithm for resolving collisions is left to the discretion of the student.

Requirements:

*  Each public method should be covered by tests
*  The methods should be documented (in English)
*  There should be no memory leaks in the program, and this should be demonstrated to the teacher when passing
*  The program should be built using cmake
  
Interface  

```
typedef student element;


struct student {
   student(unsigned age, std::string name);
   bool operator==(const student & other) const;
   long long hash() const;
   unsigned age_;
   std::string name_;
};


class linkedhs {
public:
   class iterator {
    public:
       element operator*();
       iterator operator++(int);
       iterator operator++();
       bool operator==(const iterator & other) const;
       bool operator!=(const iterator & other) const;
   };


   linkedhs();


   ~linkedhs();


   linkedhs(const linkedhs & other);
   linkedhs & operator=(const linkedhs & other);


   bool insert(const element & e);
   bool remove(const element & e);


   void swap(linkedhs & other);


   size_t size() const;


   bool empty() const;


   bool contains(const element & e) const;
   iterator find(const element & e) const;


   bool operator==(const linkedhs & other) const;
   bool operator!=(const linkedhs & other) const;


   iterator begin() const;
   iterator end() const;


   void clear();
};
```
