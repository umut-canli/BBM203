//
// Created by umut on 19.12.2022.
//

#ifndef C___BINARYSEARCHTREE_H
#define C___BINARYSEARCHTREE_H
#include "PrimaryNode.h"
#include "SecondaryNode.h"

using  namespace std;

class BinarySearchTree {
public:
    PrimaryNode *root;
    BinarySearchTree();
    PrimaryNode *insert(PrimaryNode *node, string name);
    void insert(string name);

    PrimaryNode * deleteNode(PrimaryNode *node, string name);
    PrimaryNode *search(PrimaryNode *node, string primaryName);
    PrimaryNode *findMin(PrimaryNode *node);
    void print_order(PrimaryNode* node, string &out, bool isSingleCategory, string treeName);
    SecondaryNode * findSecondaryNode(SecondaryNode *node, string name);
    void printAllItems(string &output,string whichPrimaryNodes,string treeName);

    void findPrintItems(string type, string &output, string primary, string secondary, string treeName);
    void updateData(string primary,string secondary,int data,string treeName);

    void printSecondayNodes(SecondaryNode *node, string &out);
};


#endif //C___BINARYSEARCHTREE_H