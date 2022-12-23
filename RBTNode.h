//
// Created by umut on 21.12.2022.
//

#ifndef ASSGN4_RBTNODE_H
#define ASSGN4_RBTNODE_H
#include <string>


class RBTNode {
public:
    RBTNode *left;
    RBTNode *right;
    int data;
    std::string name;
    bool color;

    RBTNode( std::string name,int data);
};


#endif //ASSGN4_RBTNODE_H
