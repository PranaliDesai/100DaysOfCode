// Copyright 2019, Kartik Madhira

#include "../linked-list/singly_linked_list.h"
#include <string>

using std::string;


class Animal {
 public:
    string name;
    int order;
    string type;
};

class Dog : public Animal {
    Dog(string _name) { 
        this->name = _name; 
        this->type = "dog";    
    }
};

class Cat : public Animal {
    Cat(string _name) {
        this->name = _name;
        this->type = "cat";
    }
};

class Shelter {
 public:
    SinglyLinkedList<Dog> dog_list;
    SinglyLinkedList<Cat> cat_list;
    Dog enque(Dog new_dog);
    Cat enque(Cat new_cat);
    Dog dequeue_dog();
    Cat dequeue_cat();
    Animal dequeue();
};