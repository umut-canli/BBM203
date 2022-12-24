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


PrimaryNode *BinarySearchTree::search(PrimaryNode *node, string primaryName) {
    if(node == nullptr || node->name == primaryName){
        return node;
    }
    else if(primaryName > node->name){
        return search(node->right, primaryName);
    }
    return search(node->left, primaryName);

}


PrimaryNode * BinarySearchTree::deleteNode(PrimaryNode *node, string name) {
    if(node == nullptr){
        return node;
    }
    else if(name > node->name){
        node->right=deleteNode(node->right, name);
    }
    else if(name < node->name){
        node->left=deleteNode(node->left, name);
    }
    else{
        if(node->right == nullptr && node->left == nullptr){
            delete node;
            node= nullptr;
            return node;
        }
        else if(node->right == nullptr){
            PrimaryNode *temp=node;
            node=node->left;
            delete temp;
        }
        else if(node->left == nullptr){
            PrimaryNode *temp=node;
            node=node->right;
            delete temp;
            return node;
        }
        else{
            PrimaryNode *temp= findMin(node->right);
            node->name=temp->name;
            node->right= deleteNode(node->right, temp->name);
        }
    }

    return node;
}


PrimaryNode *BinarySearchTree::findMin(PrimaryNode *node) {
    if(node == nullptr){
        return nullptr;
    }
    else if(node->left == nullptr){
        return node;
    }
    return findMin(node->left);

}

PrimaryNode *BinarySearchTree::insert(PrimaryNode *node, string name) {
    if(node == nullptr){
        node=new PrimaryNode(name);
        return node;
    }
    if(name > node->name)node->right=insert(node->right, name);
    else if(name < node->name) node->left=insert(node->left, name);
    return node;
}

void BinarySearchTree::insert(string name) {
    root= insert(root,name);
}

void BinarySearchTree::print_order(PrimaryNode *node, string &out, bool isSingleCategory, string treeName) {
    queue<PrimaryNode*> q;
    q.push(node);

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
SecondaryNode* BinarySearchTree::findSecondaryNode(SecondaryNode *node, string name) {
    if(node == nullptr || node->name == name){
        return node;
    }
    else if(name > node->name){
        return findSecondaryNode(node->right, name);
    }
    return findSecondaryNode(node->left, name);

}

void BinarySearchTree::printAllItems(string &output,string whichPrimaryNodes,string treeName) {
    if(whichPrimaryNodes=="all"){
        output+="command:printAllItems\n{\n";
        print_order(root, output, false,treeName);
        return;
    }
    PrimaryNode *node= search(root, whichPrimaryNodes);
    output+="command:printAllItemsInCategory\t"+node->name+"\n{\n";
    print_order(node, output, true,treeName);

}
void BinarySearchTree::updateData(string primary,string secondary,int data,string treeName){
    PrimaryNode * primaryNode= search(root, primary);
    if(treeName=="AVL")findSecondaryNode(primaryNode->getAvlTree()->root, secondary)->data=data;
    else findSecondaryNode(primaryNode->getRedBlackTree()->root, secondary)->data=data;

}

void BinarySearchTree::findPrintItems(string type, string &output, string primary, string secondary, string treeName) {
    output+="command:"+type+"\t"+primary+"\t"+secondary+"\n";
    PrimaryNode *node= search(root, primary);
    SecondaryNode *secNode;
    if(node== nullptr){
        output+="{}\n";
        return;
    }
    if(treeName=="AVL")  secNode= findSecondaryNode(node->getAvlTree()->root, secondary);
    else  secNode= findSecondaryNode(node->getRedBlackTree()->root, secondary);
    if(secNode== nullptr){
        output+="{}\n";
        return;
    }


    output+="{\n\""+node->name+"\":\n\t\""+secondary+"\":\""+ to_string(secNode->data)+"\"\n}\n";
}
