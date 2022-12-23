//
// Created by umut on 20.12.2022.
//
#include <queue>
#include "AVLTree.h"

AVLNode *AVLTree::insert(AVLNode *root, string name, int data) {
    if(root== nullptr){
        root=new AVLNode(name,data);
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

void AVLTree::preOrder(AVLNode *root) {
    if(root== nullptr){
        return;
    }
    cout<<root->name<<" : "<<root->height<<endl;
    preOrder(root->left);
    preOrder(root->right);

}

AVLNode *AVLTree::rotateRight(AVLNode *node) {
    AVLNode *temp = node->left;
    node->left=temp->right;
    temp->right=node;
    updateHeight(node);
    updateHeight(temp);

    return temp;
}

AVLNode *AVLTree::rotateLeft(AVLNode *node) {
    AVLNode *temp=node->right;
    node->right=temp->left;
    temp->left=node;
    updateHeight(node);
    updateHeight(temp);


    return temp;
}

int AVLTree::getHeight(AVLNode *node) {
    if(node== nullptr)return 0;
    return node->height;
}

void AVLTree::updateHeight(AVLNode *node) {
    node->height=max(getHeight(node->left), getHeight(node->right))+1;

}


AVLTree::AVLTree() {
    root= nullptr;
}

void AVLTree::insert(string name, int data) {
    root= insert(root,name,data);
}

AVLNode *AVLTree::deletion(AVLNode *root, string name) {
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
            AVLNode *temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left== nullptr){
            AVLNode *temp=root;
            root=root->right;
            delete temp;
        }
        else{
            AVLNode *temp= findMin(root->right);
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

AVLNode *AVLTree::findMin(AVLNode *root) {
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

int AVLTree::balanceFactor(AVLNode *node) {
    if(node== nullptr)return 0;
    return getHeight(node->left)- getHeight(node->right);
}

AVLNode *AVLTree::find(AVLNode *root,string name) {
    if(root== nullptr ||root->name==name){
        return root;
    }
    else if(name>root->name){
        return find(root->right,name);
    }
    return  find(root->left,name);
}

void AVLTree::levelorder_traversal(AVLNode *root,string &out){
    queue <AVLNode*> que;
    queue <AVLNode*> que2;
    AVLNode *item;
    que.push(root); //insert the root at first
    while(!que.empty()){
        item = que.front(); //get the element from the front end

        out+="\t\""+item->name+"\":\""+ to_string(item->data)+"\"";
        if(item->left != NULL) //When left child is present, insert into queue
            que.push(item->left);
        if(item->right != NULL) //When right child is present, insert into queue
            que.push(item->right);
        que.pop(); //remove the item from queue
    }
}
void AVLTree::print_order(AVLNode *root,string &out) {
    queue<AVLNode*> q;
    q.push(root);

    while(true){

        int length = q.size();

        if(length == 0){
            break;
        }

        int i=0;
        out+="\n\t";
        while(i<length){

            AVLNode* n = q.front();
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
AVLNode *AVLTree::findSecondaryNode(AVLNode *root, string name) {
    if(root== nullptr ||root->name==name){
        return root;
    }
    else if(name>root->name){
        return findSecondaryNode(root->right, name);
    }
    return findSecondaryNode(root->left, name);

}



