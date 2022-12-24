//
// Created by umut on 21.12.2022.
//

#include "RedBlackTree.h"
using namespace std;
#include "iostream"
#include "queue"

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

void RedBlackTree::insert(std::string name, int data) {
    root= insert(root,name,data);
    if(this->root->color)root->color= false;

}


RedBlackTree::RedBlackTree() {
    root= nullptr;
}

bool RedBlackTree::isRed(SecondaryNode *node) {
    if(node == nullptr)return false;
    return node->color;
}

SecondaryNode *RedBlackTree::rotateRight(SecondaryNode *node) {
    SecondaryNode *temp=node->left;
    node->left=temp->right;
    temp->right=node;
    temp->color=node->color;
    node->color= true;
    return temp;

}

SecondaryNode *RedBlackTree::rotateLeft(SecondaryNode *node) {
    SecondaryNode *temp=node->right;
    node->right=temp->left;
    temp->left=node;
    temp->color=node->color;
    node->color= true;
    return temp;
}

void RedBlackTree::flipcolors(SecondaryNode *node) {
    node->right->color= false;
    node->left->color= false;
    node->color= true;
}

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
            node->right= deleteMinimum(node->right);
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

SecondaryNode *RedBlackTree::findMin(SecondaryNode *node) {
    if(node == nullptr){
        return node;
    }
    else if(node->left == nullptr){
        return node;
    }
    return findMin(node->left);
}
void RedBlackTree::print_order(SecondaryNode *node, string &out) {
    queue<SecondaryNode*> queue;
    queue.push(node);

    while(true){

        int length = queue.size();

        if(length == 0){
            break;
        }

        int i=0;
        out+="\n\t";
        while(i<length){

            SecondaryNode* n = queue.front();
            out+="\""+n->name+"\":\"" + to_string(n->data)+"\",";

            if(n->left != nullptr){
                queue.push(n->left);
            }

            if(n->right != nullptr){
                queue.push(n->right);
            }

            queue.pop();
            i++;

        }
        out.pop_back();


    }
    out+="\n";
}



SecondaryNode *RedBlackTree::deleteMinimum(SecondaryNode *node) {
    if(node->left == nullptr)return nullptr;
    if(!isRed(node->left) && !isRed(node->left->left)){
        node=moveRedLeft(node);
    }
    node->left= deleteMinimum(node->left);
    if(isRed(node->right) && !isRed(node->left)) node= rotateLeft(node);
    if(isRed(node->left) && isRed(node->left->left))node=rotateRight(node);
    if(isRed(node->right) && isRed(node->left))  flipcolors(node);
    return root;
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

void RedBlackTree::deletion(string name) {
    root= deletion(root,name);
}





