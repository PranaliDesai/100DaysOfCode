// Copyright 2019, Kartik Madhira

#include "../linked-list/singly_linked_list.h"
#include <string>
#include <bits/stdc++.h>

using std::string;


class Animal {
 public:
    string name;
    int order;
    string type;
    static int timestamp;
};

static int timestamp = 0;

class Dog : public Animal {
 public:
    Dog(string _name) { 
        this->name = _name; 
        this->type = "dog";    
    }
};

class Cat : public Animal {
 public:
    Cat(string _name) {
        this->name = _name;
        this->type = "cat";
    }
};

class Shelter {
 public:
    SinglyLinkedList<Dog> dog_list;
    SinglyLinkedList<Cat> cat_list;
    void enque(Dog new_dog);
    void enque(Cat new_cat);
    Dog dequeue_dog();
    Cat dequeue_cat();
    Animal dequeue();
};

void Shelter::enque(Dog new_dog) {
    new_dog.order = timestamp++;
    cout << timestamp << "\n";
    dog_list.insert(new_dog);
}

void Shelter::enque(Cat new_cat) {
    new_cat.order = timestamp++;
    cat_list.insert(new_cat);
}

Dog Shelter::dequeue_dog() {
    if(dog_list.tail != nullptr) {
        Dog data = dog_list.tail->value;
        dog_list.tail = dog_list.tail->next;
        return data;
    } else {
        cout << "The dog list is empty!";
    }
}

Cat Shelter::dequeue_cat() {
    if(cat_list.tail != nullptr) {
        Cat data = cat_list.tail->value;
        cat_list.tail = cat_list.tail->next;
        return data;
    } else {
        cout << "The dog list is empty!";
    }
}

Animal Shelter::dequeue() {
    
    if (dog_list.tail == nullptr) {
        return (Animal)dequeue_cat();
    } 
    if (cat_list.tail == nullptr) {
        return (Animal)dequeue_dog();
    }
    if (cat_list.tail == nullptr && dog_list.tail == nullptr) {
        cout << "The shelter is empty!";
    }
    Dog oldest_dog = dog_list.tail->value;
    Cat oldest_cat = cat_list.tail->value;
    if (oldest_cat.order < oldest_dog.order) {
        return (Animal)dequeue_cat();
    } else {
        return (Animal)dequeue_dog();
    }
}

int main() {
    Shelter s;
    Dog dog1("romelu"), dog2("costa"), dog3("gerrard");
    Cat cat1("mugumeshi"), cat2("simba");
    s.enque(dog1);
    s.enque(cat1);
    s.enque(dog2);
    s.enque(cat2);
    s.enque(dog3);

    cout << s.dequeue().name << "\n";
    cout << s.dequeue().name << "\n";
    cout << s.dequeue().name << "\n";
    cout << s.dequeue().name << "\n";
    // cout << s.dequeue().name << "\n";

    return 0;
}