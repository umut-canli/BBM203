//
// Created by umut on 20.12.2022.
//
#include <queue>
#include "AVLTree.h"

SecondaryNode *AVLTree::insert(SecondaryNode *root, string name, int data) {
    if(root== nullptr){
        root=new SecondaryNode(name,data);
        root->height=1;
        return root;

    }
    else if(name > root->name) root->right= insert(root->right,name,data);
    else if(name<root->name) root->left= insert(root->left,name,data);
    if(getHeight(root->left)> getHeight(root->right)){
        root->height= getHeight(root->left)+1;
    }
    else{
        root->height= getHeight(root->right)+1;
    }


    if((getHeight(root->left)- getHeight(root->right))==2){

        if(name<root->left->name){
            return rotateRight(root);
        }
        root->left = rotateLeft(root->left);
        return rotateRight(root);

    }
    if((getHeight(root->left)- getHeight(root->right))==-2){

        if(name>root->right->name){
            return rotateLeft(root);
        }
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }



    return root;
}

void AVLTree::preOrder(SecondaryNode *root) {
    if(root== nullptr){
        return;
    }
    cout<<root->name<<" : "<<root->height<<endl;
    preOrder(root->left);
    preOrder(root->right);

}

SecondaryNode *AVLTree::rotateRight(SecondaryNode *node) {
    SecondaryNode *temp = node->left;
    node->left=temp->right;
    temp->right=node;
    updateHeight(node);
    updateHeight(temp);

    return temp;
}

SecondaryNode *AVLTree::rotateLeft(SecondaryNode *node) {
    SecondaryNode *temp=node->right;
    node->right=temp->left;
    temp->left=node;
    updateHeight(node);
    updateHeight(temp);


    return temp;
}

int AVLTree::getHeight(SecondaryNode *node) {
    if(node== nullptr)return 0;
    return node->height;
}

void AVLTree::updateHeight(SecondaryNode *node) {
    node->height=max(getHeight(node->left), getHeight(node->right))+1;

}


AVLTree::AVLTree() {
    root= nullptr;
}

void AVLTree::insert(string name, int data) {
    root= insert(root,name,data);
}

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

SecondaryNode *AVLTree::findMin(SecondaryNode *root) {
    if(root== nullptr){
        return nullptr;
    }
    else if(root->left== nullptr){
        return root;
    }
    return findMin(root->left);

}

void AVLTree::deletion(string name) {
    root= deletion(root,name);

}

int AVLTree::balanceFactor(SecondaryNode *node) {
    if(node== nullptr)return 0;
    return getHeight(node->left)- getHeight(node->right);
}

SecondaryNode *AVLTree::find(SecondaryNode *root,string name) {
    if(root== nullptr ||root->name==name){
        return root;
    }
    else if(name>root->name){
        return find(root->right,name);
    }
    return  find(root->left,name);
}


void AVLTree::print_order(SecondaryNode *root,string &out) {
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
SecondaryNode *AVLTree::findSecondaryNode(SecondaryNode *root, string name) {
    if(root== nullptr ||root->name==name){
        return root;
    }
    else if(name>root->name){
        return findSecondaryNode(root->right, name);
    }
    return findSecondaryNode(root->left, name);

}



