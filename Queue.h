#ifndef QUEUE_H
#define QUEUE_H

#include "node2.h"
#include <iostream>
#include <string>
using namespace std;

#define N 3

int array_menu[N][2] = {{1,100},{2,200},{3,50}};
string name_menu[N] = {"Ramen", "Somtum", "Fried Chicken"};

class Queue {
    NodePtr headPtr, tailPtr;
    int size;
public:
    Queue();
    ~Queue();
    void enqueue(int, int);
    int dequeue();
    bool is_empty();
    int get_size();
};

Queue::Queue() {
    headPtr = nullptr;
    tailPtr = nullptr;
    size = 0;
}

Queue::~Queue() {
    NodePtr current = headPtr;
    while(current != nullptr) {
        NodePtr temp = current;
        current = current->get_next();
        delete temp;
    }
}

void Queue::enqueue(int x, int y) {
    NodePtr new_node = new NODE(x, y);
    if(headPtr == nullptr) {
        headPtr = new_node;
    } else {
        tailPtr->set_next(new_node);
    }
    tailPtr = new_node;
    cout << "My order is " << x << endl;
    size++;
}

int Queue::dequeue() {
    if(size == 0) {
        cout << "The queue is empty" << endl;
        return -1;
    }

    NodePtr t = headPtr;
    headPtr = headPtr->get_next();
    if(headPtr == nullptr) tailPtr = nullptr;

    int menu = t->get_menu();
    int amount = t->get_amount();
    int total = 0;

    for(int i = 0; i < N; i++) {
        if(menu == array_menu[i][0]) {
            total = amount * array_menu[i][1];
            break;
        }
    }

    cout << name_menu[menu-1] << endl;
    cout << "You have to pay " << total << endl;

    int cash;
    cout << "Cash: ";
    cin >> cash;
    while(cash < total) {
        cout << "Cash: ";
        cin >> cash;
    }

    cout << "Thank you" << endl;
    if(cash > total) {
        cout << "Change is: " << (cash - total) << endl;
    }

    delete t;
    size--;
    return total;
}

bool Queue::is_empty() {
    return headPtr == nullptr;
}

int Queue::get_size() {
    return size;
}

#endif
