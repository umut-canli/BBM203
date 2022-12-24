//
// Created by umut on 20.12.2022.
//

#ifndef ASSGN4_AVLTREE_H
#define ASSGN4_AVLTREE_H
#include "SecondaryNode.h"

class AVLTree {
public:
    SecondaryNode *root;

    AVLTree();

    SecondaryNode *insert(SecondaryNode *node, string nodeName, int data);
    void insert(string name,int data);
    void deletion(string name);
    SecondaryNode *deletion(SecondaryNode *root, string name);
    SecondaryNode *rotateLeft(SecondaryNode *node);
    SecondaryNode *rotateRight(SecondaryNode *node);
    int getHeight(SecondaryNode *node);
    void updateHeight(SecondaryNode *node);
    SecondaryNode *findMin(SecondaryNode *node);
    int balanceFactor(SecondaryNode *node);
    SecondaryNode *find(SecondaryNode *node, string name);
    void print_order(SecondaryNode *node, string &out);
    SecondaryNode *findSecondaryNode(SecondaryNode *node, string name);
};


#endif //ASSGN4_AVLTREE_H
