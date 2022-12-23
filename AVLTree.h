//
// Created by umut on 20.12.2022.
//

#ifndef ASSGN4_AVLTREE_H
#define ASSGN4_AVLTREE_H
#include "AVLNode.h"
#include "SecondaryNode.h"

class AVLTree {
public:
    SecondaryNode *root;

    AVLTree();

    SecondaryNode *insert(SecondaryNode *root, string name, int data);
    void insert(string name,int data);
    void deletion(string name);
    SecondaryNode *deletion(SecondaryNode *root, string name);
    void preOrder(SecondaryNode *root);
    SecondaryNode *rotateLeft(SecondaryNode *node);
    SecondaryNode *rotateRight(SecondaryNode *node);
    int getHeight(SecondaryNode *node);
    void updateHeight(SecondaryNode *node);
    SecondaryNode *findMin(SecondaryNode *root);
    int balanceFactor(SecondaryNode *node);
    SecondaryNode *find(SecondaryNode *root, string name);

    void print_order(SecondaryNode *root,string &out);

    SecondaryNode *findSecondaryNode(SecondaryNode *root, string name);
};


#endif //ASSGN4_AVLTREE_H
