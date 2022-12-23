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
     void printLevelOrder(PrimaryNode *root);
     void printLevelOrder(AVLNode *root);
     int height(PrimaryNode *root);
     int height(AVLNode *root);

    void printGivenLevel(PrimaryNode *root, int level);
    void printGivenLevel1(AVLNode *root, int level);
    bool printLevel(PrimaryNode *node,int level);
    void levelOrder(PrimaryNode *root);
    void levelorder_traversal(PrimaryNode *root,string &out,bool isprintAll);
    void print_order(PrimaryNode* root,string &out,bool isSingleCategory);

    void current_height(PrimaryNode *root, int level);

    AVLNode *findSecondaryNode(AVLNode *root, string name);
};


#endif //C___BINARYSEARCHTREE_H