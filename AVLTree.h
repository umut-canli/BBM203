//
// Created by umut on 20.12.2022.
//

#ifndef ASSGN4_AVLTREE_H
#define ASSGN4_AVLTREE_H
#include "AVLNode.h"

class AVLTree {
public:
    AVLNode *root;

    AVLTree();

    AVLNode *insert(AVLNode *root, string name, int data);
    void insert(string name,int data);
    void deletion(string name);
    AVLNode *deletion(AVLNode *root, string name);
    void preOrder(AVLNode *root);
    AVLNode *rotateLeft(AVLNode *node);
    AVLNode *rotateRight(AVLNode *node);
    int getHeight(AVLNode *node);
    void updateHeight(AVLNode *node);
    AVLNode *findMin(AVLNode *root);
    AVLNode *find(AVLNode *root);
    AVLNode *getNode(string name,int data);
    int balanceFactor(AVLNode *node);
    void levelorder_traversal(AVLNode *root,string &out);
    void current_height(AVLNode *root, int level);

    AVLNode *find(AVLNode *root, string name);

    void print_order(AVLNode *root,string &out);

    AVLNode *findSecondaryNode(AVLNode *root, string name);
};


#endif //ASSGN4_AVLTREE_H
