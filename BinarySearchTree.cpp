//
// Created by umut on 19.12.2022.
//

#include "BinarySearchTree.h"
#include <iostream>
#include <queue>
using namespace std;



BinarySearchTree::BinarySearchTree() {
    root= nullptr;

}


PrimaryNode *BinarySearchTree::Search(PrimaryNode *root, string name) {
    if(root== nullptr ||root->name==name){
        return root;
    }
    else if(name>root->name){
        return Search(root->right,name);
    }
    return  Search(root->left,name);

}

void BinarySearchTree::preOrder(PrimaryNode *root) {
    if(root== nullptr){
        return;
    }
    cout<<root->name<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

PrimaryNode * BinarySearchTree::deleteNode(PrimaryNode *root,string name) {
    if(root==nullptr){
        return root;
    }
    else if(name>root->name){
        root->right=deleteNode(root->right,name);
    }
    else if(name<root->name){
        root->left=deleteNode(root->left,name);
    }
    else{
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root= nullptr;
            return root;
        }
        else if(root->right == nullptr){
            PrimaryNode *temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left == nullptr){
            PrimaryNode *temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else{
            PrimaryNode *temp= findMin(root->right);
            root->name=temp->name;
            root->right= deleteNode(root->right,temp->name);
        }
    }

    return root;
}

PrimaryNode *BinarySearchTree::findMax(PrimaryNode *root) {
    if(root== nullptr){
        return nullptr;
    }
    else if(root->right== nullptr){
        return root;
    }
    else{
        return findMax(root->right);
    }
}

PrimaryNode *BinarySearchTree::findMin(PrimaryNode *root) {
    if(root== nullptr){
        return nullptr;
    }
    else if(root->left== nullptr){
        return root;
    }
    else{
        findMin(root->left);
    }
}

PrimaryNode *BinarySearchTree::insert(PrimaryNode *root,string name) {
    if(root== nullptr){
        root=new PrimaryNode(name);
        return root;
    }
    if(name>root->name)root->right=insert(root->right,name);
    else if(name<root->name) root->left=insert(root->left,name);
    return root;
}

void BinarySearchTree::insert(string name) {
    root= insert(root,name);
}

int BinarySearchTree::height(SecondaryNode *root) {
    if (root == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(root->left);
        int rheight = height(root->right);

        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }}




void BinarySearchTree::print_order(PrimaryNode *root,string &out,bool isSingleCategory,string treeName) {
    queue<PrimaryNode*> q;
    q.push(root);

    while(true){

        int length = q.size();

        if(length == 0){
            break;
        }

        int i=0;

        while(i<length){
            PrimaryNode* n = q.front();
            out+="\""+n->name+"\":";
            if(treeName=="AVL"){
                if(n->getAvlTree()->root != nullptr){
                    n->getAvlTree()->print_order(n->getAvlTree()->root, out);
                }
                else{
                    out+="{}\n";
                }
            }
            else{
                if(n->getRedBlackTree()->root != nullptr){
                    n->getRedBlackTree()->print_order(n->getRedBlackTree()->root, out);
                }
                else{
                    out+="{}\n";
                }
            }




            if(n->left != NULL){
                q.push(n->left);
            }

            if(n->right != NULL){
                q.push(n->right);
            }

            q.pop();
            i++;

        }
    if(isSingleCategory) break;

    }
    out+="}\n";

}
SecondaryNode* BinarySearchTree::findSecondaryNode(SecondaryNode *root, string name) {
    if(root== nullptr ||root->name==name){
        return root;
    }
    else if(name>root->name){
        return findSecondaryNode(root->right, name);
    }
    return findSecondaryNode(root->left, name);

}

void BinarySearchTree::printAllItems(string &output,string whichPrimaryNodes,string treeName) {
    if(whichPrimaryNodes=="all"){
        output+="command:printAllItems\n{\n";
        print_order(root, output, false,treeName);
        return;
    }
    PrimaryNode *node=Search(root,whichPrimaryNodes);
    output+="command:printAllItemsInCategory\t"+node->name+"\n{\n";
    print_order(node, output, true,treeName);

}
void BinarySearchTree::updateData(string primary,string secondary,int data){
    PrimaryNode * primaryNode= Search(root,primary);
    findSecondaryNode(primaryNode->getAvlTree()->root, secondary)->data=data;
}

void BinarySearchTree::find(string type,string &output,string primary, string secondary) {
    output+="command:"+type+"\t"+primary+"\t"+secondary+"\n";
    PrimaryNode *node=Search(root,primary);
    if(node== nullptr){
        output+="{}\n";
        return;
    }
    SecondaryNode *secNode= findSecondaryNode(node->getAvlTree()->root, secondary);
    if(secNode== nullptr){
        output+="{}\n";
        return;
    }


    output+="{\n\""+node->name+"\":\n\t\""+secondary+"\":\""+ to_string(secNode->data)+"\"\n}\n";
}
