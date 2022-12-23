//
// Created by umut on 21.12.2022.
//

#ifndef ASSGN4_REDBLACKTREE_H
#define ASSGN4_REDBLACKTREE_H
#include "SecondaryNode.h"

class RedBlackTree {
public:
    SecondaryNode *root;
    SecondaryNode *insert(SecondaryNode *root,std::string name,int data);
    void insert(std::string name,int data);
    void preOrder(SecondaryNode *root);
    bool isRed(SecondaryNode *root);
    SecondaryNode *rotateLeft(SecondaryNode *root);
    SecondaryNode *rotateRight(SecondaryNode *root);
    void flipcolors(SecondaryNode *root);
    SecondaryNode *deletion(SecondaryNode *root,std::string name,int data);
    SecondaryNode *findMin(SecondaryNode *root);

    RedBlackTree();

    void print_order(SecondaryNode *root, string &out);
};


#endif //ASSGN4_REDBLACKTREE_H
