//
// Created by umut on 12/2/22.
//

#ifndef ASSGN3_NODE_H
#define ASSGN3_NODE_H
using namespace std;
#include "iostream"
class Node {

public:
    int ID;
    double brewTime;
    double orderTime;
    double price;
    Node *next;
    Node(int ID,double brewTime ,double orderTime,double price);
};


#endif //ASSGN3_NODE_H
