//
// Created by umut on 19.12.2022.
//

#ifndef C___PRIMARYNODE_H
#define C___PRIMARYNODE_H
#include "string"
#include "AVLTree.h"
#include "RedBlackTree.h"
#include "SecondaryNode.h"
using namespace std;

class PrimaryNode {

public:
    PrimaryNode(string name);
    PrimaryNode *left;
    PrimaryNode *right;
    string name;
    AVLTree *avlTree;
    RedBlackTree *redBlackTree;
    AVLTree *getAvlTree() ;
    RedBlackTree *getRedBlackTree() ;
};


#endif //C___PRIMARYNODE_H