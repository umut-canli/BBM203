//
// Created by umut on 21.12.2022.
//

#include "RedBlackTree.h"
using namespace std;
#include "iostream"

RBTNode *RedBlackTree::insert(RBTNode *root, std::string name, int data) {
    if(this->root== nullptr){
        root=new RBTNode(name,data);
        root->color=false;
        return root;
    }
    else if(root== nullptr){
        root=new RBTNode(name,data);
        return root;
    }
    else if(name>root->name) root->right= insert(root->right,name,data);
    else if(name<root->name) root->left= insert(root->left,name,data);

    if(isRed(root->right)&& !isRed(root->left)) root= rotateLeft(root);
    if(isRed(root->left)&& isRed(root->left->left))root=rotateRight(root);
    if(isRed(root->right)&& isRed(root->left))  flipcolors(root);

    return root;
}

void RedBlackTree::insert(std::string name, int data) {
    root= insert(root,name,data);
    if(this->root->color)root->color= false;

}

void RedBlackTree::preOrder(RBTNode *root) {
    if(root== nullptr){
        return;
    }
    cout<<root->name<<" : "<<root->color<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

RedBlackTree::RedBlackTree() {
    root= nullptr;
}

bool RedBlackTree::isRed(RBTNode *root) {
    if(root== nullptr)return false;
    return root->color;
}

RBTNode *RedBlackTree::rotateRight(RBTNode *root) {
    RBTNode *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    temp->color=root->color;
    root->color= true;
    return temp;

}

RBTNode *RedBlackTree::rotateLeft(RBTNode *root) {
    cout<<root->name<<endl;
    RBTNode *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    temp->color=root->color;
    root->color= true;
    return temp;
}

void RedBlackTree::flipcolors(RBTNode *root) {
    root->right->color= false;
    root->left->color= false;
    root->color= true;
}

RBTNode *RedBlackTree::deletion(RBTNode *root, std::string name, int data) {
    if(root== nullptr){
        return root;
    }
    else if(name>root->name)root->right= deletion(root->right,name,data);
    else if(name<root->name)root->left= deletion(root->left,name,data);
    else{
        if(root->right== nullptr && root->left== nullptr){
            delete root;
            root= nullptr;
            return root;
        }
        else if(root->right== nullptr){
            RBTNode *temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left== nullptr){
            RBTNode *temp=root;
            root=root->right;
            root->color=false;
            delete temp;
        }
        else{
            RBTNode *min= findMin(root->right);
            root->data=min->data;
            root->name=min->name;
            if((!root->color)&&(min->color))root->color=false;
            else if((root->color)&&!(min->color))
            root->right= deletion(root->right,min->name,min->data);
        }
    }

}

RBTNode *RedBlackTree::findMin(RBTNode *root) {
    if(root== nullptr){
        return root;
    }
    else if(root->left== nullptr){
        return root;
    }
    return findMin(root->left);
}



