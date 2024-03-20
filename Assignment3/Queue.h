//
// Created by umut on 12/4/22.
//

#ifndef ASSGN3_QUEUE_H
#define ASSGN3_QUEUE_H
#include "Node.h"
#include "Customer.h"

class Queue {
public:
    Node *front;
    Node *rear;
    int size;

    void enQueueBarista(int ID,double orderTime,double brewTime ,double price);
    void enQueueCashier(int ID,double orderTime,double brewTime ,double price);
    void deQueue();
    Queue();
};


#endif //ASSGN3_QUEUE_H
