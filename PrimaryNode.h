//
// Created by umut on 19.12.2022.
//

#ifndef C___PRIMARYNODE_H
#define C___PRIMARYNODE_H
#include "string"
#include "AVLTree.h"
#include "RedBlackTree.h"
using namespace std;

class PrimaryNode {

public:
    PrimaryNode();
    PrimaryNode(string name);
    PrimaryNode *left;
    PrimaryNode *right;
    std::string name;
    AVLTree *tree;
    RedBlackTree *rbt;

    AVLTree *getTree() const;

    RedBlackTree *getRbt() const;
};


#endif //C___PRIMARYNODE_H