//
// Created by umut on 21.12.2022.
//

#include "RedBlackTree.h"
using namespace std;
#include "iostream"
#include "queue"
//inserting new elements and balancing  the Red Black Tree.

SecondaryNode *RedBlackTree::insert(SecondaryNode *node, std::string name, int data) {

    if(node == nullptr){
        node=new SecondaryNode(name, data);
        node->color= true;
        return node;
    }
    else if(name > node->name) node->right= insert(node->right, name, data);
    else if(name < node->name) node->left= insert(node->left, name, data);

    if(isRed(node->right) && !isRed(node->left)) node= rotateLeft(node);
    if(isRed(node->left) && isRed(node->left->left))node=rotateRight(node);
    if(isRed(node->right) && isRed(node->left))  flipcolors(node);

    return node;
}
//updating the root.
void RedBlackTree::insert(std::string name, int data) {
    root= insert(root,name,data);
    if(this->root->color)root->color= false;

}


RedBlackTree::RedBlackTree() {
    root= nullptr;
}
//checking if the given node is red.
bool RedBlackTree::isRed(SecondaryNode *node) {
    if(node == nullptr)return false;
    return node->color;
}
//rotating right
SecondaryNode *RedBlackTree::rotateRight(SecondaryNode *node) {
    SecondaryNode *temp=node->left;
    node->left=temp->right;
    temp->right=node;
    temp->color=node->color;
    node->color= true;
    return temp;

}
//rotating left
SecondaryNode *RedBlackTree::rotateLeft(SecondaryNode *node) {
    SecondaryNode *temp=node->right;
    node->right=temp->left;
    temp->left=node;
    temp->color=node->color;
    node->color= true;
    return temp;
}
//flipping the colors.
void RedBlackTree::flipcolors(SecondaryNode *node) {
    node->right->color= false;
    node->left->color= false;
    node->color= true;
}
//deleting the named node and rebalancing the Red Black Tree
SecondaryNode *RedBlackTree::deletion(SecondaryNode *node, std::string name) {
    if(name < node->name){
        if(!isRed(node->left) && !isRed(node->left->left)){
            node= moveRedLeft(node);
        }
        node->left= deletion(node->left, name);
    }
    else{
        if(isRed(node->left)){
            node= rotateRight(node);
        }
        if(node->name == name && node->right == nullptr){
            delete node;
            return nullptr;
        }
        if(!isRed(node->right) && !isRed(node->right->left)){
            node= moveRedRight(node);
        }
        if(node->name == name){
            SecondaryNode *min= findMin(node->right);
            node->name=min->name;
            node->data=min->data;
            node->right=  deletion(min,min->name);
        }
        else{
            node->right= deletion(node->right, name);
        }

    }
    if(isRed(node->right) && !isRed(node->left)) node= rotateLeft(node);
    if(isRed(node->left) && isRed(node->left->left))node=rotateRight(node);
    if(isRed(node->right) && isRed(node->left))  flipcolors(node);
    return node;
}
//finds the lowest element in subtree.

SecondaryNode *RedBlackTree::findMin(SecondaryNode *node) {
    if(node == nullptr){
        return node;
    }
    else if(node->left == nullptr){
        return node;
    }
    return findMin(node->left);
}

SecondaryNode *RedBlackTree::moveRedLeft(SecondaryNode *node) {
    flipcolors(node);
    if(isRed(node->right->left)){
        node->right= rotateRight(node->right);
        node= rotateLeft(node);
        flipcolors(node);
    }
    return node;
}
SecondaryNode *RedBlackTree::moveRedRight(SecondaryNode *node) {
    flipcolors(node);
    if(!isRed(node->left->left)){
        node= rotateRight(node);
        flipcolors(node);
    }
    return node;
}
//after the deletion part,updating the root.
void RedBlackTree::deletion(string name) {
    root= deletion(root,name);
}





