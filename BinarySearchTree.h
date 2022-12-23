//
// Created by umut on 19.12.2022.
//

#ifndef C___BINARYSEARCHTREE_H
#define C___BINARYSEARCHTREE_H
#include "PrimaryNode.h"

using  namespace std;

class BinarySearchTree {
public:
    PrimaryNode *root;
    BinarySearchTree();
    PrimaryNode *createNode(string name);
    PrimaryNode *insert(PrimaryNode *root,string name);
    void insert(string name);
    PrimaryNode * deleteNode(PrimaryNode *root,string name);
    PrimaryNode *Search(PrimaryNode *root,string name);
    void preOrder(PrimaryNode *root);
    void insert2(PrimaryNode* &root,string name);
    PrimaryNode *findMin(PrimaryNode *root);
    PrimaryNode *findMax(PrimaryNode *root);
     int height(AVLNode *root);
    void print_order(PrimaryNode* root,string &out,bool isSingleCategory);
    AVLNode *findSecondaryNode(AVLNode *root, string name);
    void printAllItems(string &output,string whichPrimaryNodes);
    void find(string type,string &output,string primary,string secondary);
    void updateData(string primary,string secondary,int data);
};


#endif //C___BINARYSEARCHTREE_H