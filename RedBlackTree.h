//
// Created by umut on 21.12.2022.
//

#ifndef ASSGN4_REDBLACKTREE_H
#define ASSGN4_REDBLACKTREE_H
#include "RBTNode.h"

class RedBlackTree {
public:
    RBTNode *root;
    RBTNode *insert(RBTNode *root,std::string name,int data);
    void insert(std::string name,int data);
    void preOrder(RBTNode *root);
    bool isRed(RBTNode *root);
    RBTNode *rotateLeft(RBTNode *root);
    RBTNode *rotateRight(RBTNode *root);
    void flipcolors(RBTNode *root);
    RBTNode *deletion(RBTNode *root,std::string name,int data);
    RBTNode *findMin(RBTNode *root);
    RBTNode *fixdelete(RBTNode *root);

    RedBlackTree();
};


#endif //ASSGN4_REDBLACKTREE_H
