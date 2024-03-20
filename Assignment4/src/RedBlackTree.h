//
// Created by umut on 21.12.2022.
//

#ifndef ASSGN4_REDBLACKTREE_H
#define ASSGN4_REDBLACKTREE_H
#include "SecondaryNode.h"

class RedBlackTree {
public:
    SecondaryNode *root;
    RedBlackTree();
    SecondaryNode *findMin(SecondaryNode *node);

    SecondaryNode *insert(SecondaryNode *node, std::string name, int data);
    void insert(std::string name,int data);

    SecondaryNode *deletion(SecondaryNode *node, std::string name);
    void deletion(string name);

    bool isRed(SecondaryNode *node);
    SecondaryNode *rotateLeft(SecondaryNode *node);
    SecondaryNode *rotateRight(SecondaryNode *node);
    void flipcolors(SecondaryNode *node);


    SecondaryNode *moveRedLeft(SecondaryNode *node);
    SecondaryNode *moveRedRight(SecondaryNode *node);


};


#endif //ASSGN4_REDBLACKTREE_H
