//
// Created by umut on 12/2/22.
//

#include "Node.h"




Node::Node(int ID, double brewTime, double orderTime, double price) {
    this->ID=ID;
    this->brewTime=brewTime;
    this->orderTime=orderTime;
    this->price=price;
    next = NULL;

}
