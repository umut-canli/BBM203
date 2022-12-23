//
// Created by umut on 23.12.2022.
//

#ifndef ASSGN4_SECONDARYNODE_H
#define ASSGN4_SECONDARYNODE_H
#include "string"
using namespace std;
class SecondaryNode {
public:

    SecondaryNode *left;
    SecondaryNode *right;
    int data;
    string name;
    bool color;
    int height;

    explicit SecondaryNode(string name,int data);

    void print_order(SecondaryNode *root, string &out);
};


#endif //ASSGN4_SECONDARYNODE_H
