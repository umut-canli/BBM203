//
// Created by umut on 20.12.2022.
//

#ifndef ASSGN4_AVLNODE_H
#define ASSGN4_AVLNODE_H
using namespace std;
#include "iostream"

class AVLNode {
public:
    AVLNode();

    AVLNode(string name, int data);
    AVLNode *left;
    AVLNode *right;
    string name;
    int data;
    int height;

private:

};


#endif //ASSGN4_AVLNODE_H
