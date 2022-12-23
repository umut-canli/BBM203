//
// Created by umut on 21.12.2022.
//

#include "RBTNode.h"

RBTNode::RBTNode(std::string name, int data) {
    this->name=name;
    this->data=data;
    left= nullptr;
    right= nullptr;
    color= true;
}
