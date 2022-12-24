//
// Created by umut on 20.12.2022.
//
#include <queue>
#include "AVLTree.h"
//inserting new elements and balancing  the AVL tree
SecondaryNode *AVLTree::insert(SecondaryNode *node, string nodeName, int data) {
    if(node == nullptr){
        node=new SecondaryNode(nodeName, data);
        node->height=1;
        return node;

    }
    else if(nodeName > node->name) node->right= insert(node->right, nodeName, data);
    else if(nodeName < node->name) node->left= insert(node->left, nodeName, data);
    if(getHeight(node->left) > getHeight(node->right)){
        node->height= getHeight(node->left) + 1;
    }
    else{
        node->height= getHeight(node->right) + 1;
    }


    if((getHeight(node->left) - getHeight(node->right)) == 2){

        if(nodeName < node->left->name){
            return rotateRight(node);
        }
        node->left = rotateLeft(node->left);
        return rotateRight(node);

    }
    if((getHeight(node->left) - getHeight(node->right)) == -2){

        if(nodeName > node->right->name){
            return rotateLeft(node);
        }
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }



    return node;
}
//rotating right the node
SecondaryNode *AVLTree::rotateRight(SecondaryNode *node) {
    SecondaryNode *temp = node->left;
    node->left=temp->right;
    temp->right=node;
    updateHeight(node);
    updateHeight(temp);

    return temp;
}
//rotating left the node.
SecondaryNode *AVLTree::rotateLeft(SecondaryNode *node) {
    SecondaryNode *temp=node->right;
    node->right=temp->left;
    temp->left=node;
    updateHeight(node);
    updateHeight(temp);


    return temp;
}
//finding height of the node.
int AVLTree::getHeight(SecondaryNode *node) {
    if(node== nullptr)return 0;
    return node->height;
}
//updating height of the node.
void AVLTree::updateHeight(SecondaryNode *node) {
    node->height=max(getHeight(node->left), getHeight(node->right))+1;

}


AVLTree::AVLTree() {
    root= nullptr;
}

void AVLTree::insert(string name, int data) {
    root= insert(root,name,data);
}
//deleting and rebalancing the named node in AVL tree
SecondaryNode *AVLTree::deletion(SecondaryNode *root, string name) {
    if(root== nullptr){
        return root;
    }
    else if(root->name<name){
        root->right=deletion(root->right, name);
    }

    else if(root->name>name)root->left=deletion(root->left, name);
    else{
        if(root->right== nullptr &&root->left== nullptr){
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
            delete temp;
        }
        else{
            SecondaryNode *temp= findMin(root->right);
            root->data=temp->data;
            root->name=temp->name;
            root->right= deletion(root->right, temp->name);
        }
    }
    if(getHeight(root->left)> getHeight(root->right)){
        root->height= getHeight(root->left)+1;
    }
    else{
        root->height= getHeight(root->right)+1;
    }

    if(balanceFactor(root)==2){

        if(balanceFactor(root->left)>=0){
            return rotateRight(root);
        }
        root->left = rotateLeft(root->left);
        return rotateRight(root);

    }
    if(balanceFactor(root)==-2){

        if(balanceFactor(root->right)<=0){
            return rotateLeft(root);
        }
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;

}
//finds the lowest element in subtree.
SecondaryNode *AVLTree::findMin(SecondaryNode *node) {
    if(node == nullptr){
        return nullptr;
    }
    else if(node->left == nullptr){
        return node;
    }
    return findMin(node->left);

}

void AVLTree::deletion(string name) {
    root= deletion(root,name);

}
//getting the balance factor of  node.
int AVLTree::balanceFactor(SecondaryNode *node) {
    if(node== nullptr)return 0;
    return getHeight(node->left)- getHeight(node->right);
}




