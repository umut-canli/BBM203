//
// Created by umut on 21.12.2022.
//

#include "RedBlackTree.h"
using namespace std;
#include "iostream"
#include "queue"

SecondaryNode *RedBlackTree::insert(SecondaryNode *root, std::string name, int data) {

    if(root== nullptr){
        root=new SecondaryNode(name,data);
        root->color= true;
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

void RedBlackTree::preOrder(SecondaryNode *root) {
    if(root== nullptr){
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
}

RedBlackTree::RedBlackTree() {
    root= nullptr;
}

bool RedBlackTree::isRed(SecondaryNode *root) {
    if(root== nullptr)return false;
    return root->color;
}

SecondaryNode *RedBlackTree::rotateRight(SecondaryNode *root) {
    SecondaryNode *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    temp->color=root->color;
    root->color= true;
    return temp;

}

SecondaryNode *RedBlackTree::rotateLeft(SecondaryNode *root) {
    SecondaryNode *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    temp->color=root->color;
    root->color= true;
    return temp;
}

void RedBlackTree::flipcolors(SecondaryNode *root) {
    root->right->color= false;
    root->left->color= false;
    root->color= true;
}

SecondaryNode *RedBlackTree::deletion(SecondaryNode *root, std::string name, int data) {
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
            SecondaryNode *temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left== nullptr){
            SecondaryNode *temp=root;
            root=root->right;
            root->color=false;
            delete temp;
        }
        else{
            SecondaryNode *min= findMin(root->right);
            root->data=min->data;
            root->name=min->name;
            if((!root->color)&&(min->color))root->color=false;
            else if((root->color)&&!(min->color))
            root->right= deletion(root->right,min->name,min->data);
        }
    }

}

SecondaryNode *RedBlackTree::findMin(SecondaryNode *root) {
    if(root== nullptr){
        return root;
    }
    else if(root->left== nullptr){
        return root;
    }
    return findMin(root->left);
}
void RedBlackTree::print_order(SecondaryNode *root, string &out) {
    queue<SecondaryNode*> q;
    q.push(root);

    while(true){

        int length = q.size();

        if(length == 0){
            break;
        }

        int i=0;
        out+="\n\t";
        while(i<length){

            SecondaryNode* n = q.front();
            out+="\""+n->name+"\":\"" + to_string(n->data)+"\",";

            if(n->left != NULL){
                q.push(n->left);
            }

            if(n->right != NULL){
                q.push(n->right);
            }

            q.pop();
            i++;

        }
        out.pop_back();


    }
    out+="\n";
}



