//
// Created by umut on 23.12.2022.
//

#ifndef ASSGN4_SECONDARYTREE_H
#define ASSGN4_SECONDARYTREE_H


#include "SecondaryNode.h"

class SecondaryTree {
public:
    void preOrder(SecondaryNode *root);
    SecondaryNode *findMin(SecondaryNode *root);
    SecondaryNode *find(SecondaryNode *root, string name);
    void print_order(SecondaryNode *root,string &out);




};


#endif //ASSGN4_SECONDARYTREE_H
