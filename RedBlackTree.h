//
// Created by umut on 21.12.2022.
//

#ifndef ASSGN4_REDBLACKTREE_H
#define ASSGN4_REDBLACKTREE_H
#include "SecondaryNode.h"

class RedBlackTree {
public:
    SecondaryNode *root;

    SecondaryNode *insert(SecondaryNode *node, std::string name, int data);
    void insert(std::string name,int data);

    SecondaryNode *deletion(SecondaryNode *node, std::string name);
    void deletion(string name);

    bool isRed(SecondaryNode *node);
    SecondaryNode *rotateLeft(SecondaryNode *node);
    SecondaryNode *rotateRight(SecondaryNode *node);
    void flipcolors(SecondaryNode *node);
    SecondaryNode *findMin(SecondaryNode *node);
    RedBlackTree();
    void print_order(SecondaryNode *node, string &out);
    SecondaryNode *deleteMinimum(SecondaryNode *node);
    SecondaryNode *moveRedLeft(SecondaryNode *node);
    SecondaryNode *moveRedRight(SecondaryNode *node);


    void deleteMinimum();
};


#endif //ASSGN4_REDBLACKTREE_H
