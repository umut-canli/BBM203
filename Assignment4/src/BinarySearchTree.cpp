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

//finds the named node and returns it.
PrimaryNode *BinarySearchTree::search(PrimaryNode *node, string primaryName) {
    if(node == nullptr || node->name == primaryName){
        return node;
    }
    else if(primaryName > node->name){
        return search(node->right, primaryName);
    }
    return search(node->left, primaryName);

}

//deletes the named node.
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

//finds the lowest element in subtree.
PrimaryNode *BinarySearchTree::findMin(PrimaryNode *node) {
    if(node == nullptr){
        return nullptr;
    }
    else if(node->left == nullptr){
        return node;
    }
    return findMin(node->left);

}
//inserting new primary nodes to binary search tree .
PrimaryNode *BinarySearchTree::insert(PrimaryNode *node, string name) {
    if(node == nullptr){
        node=new PrimaryNode(name);
        return node;
    }
    if(name > node->name)node->right=insert(node->right, name);
    else if(name < node->name) node->left=insert(node->left, name);
    return node;
}
//updating the root.
// I need to update the root every time so if I want to insert a new node I am calling this function.After that this function
//is calling the real insert function .Then the real insert function returning updated binary search tree so I am updating the root.
void BinarySearchTree::insert(string name) {
    root= insert(root,name);
}
//If I am calling  print_order for "printAllItemsInCategory" ,function is turning 1 time then loop is breaking.
void BinarySearchTree::print_order(PrimaryNode *node, string &out, bool isSingleCategory, string treeName) {
    queue<PrimaryNode*> queue;
    queue.push(node);

    while(true){

        int length = queue.size();

        if(length == 0){
            break;
        }

        int i=0;

        while(i<length){
            PrimaryNode* n = queue.front();
            out+="\""+n->name+"\":";
            if(treeName=="AVL"){
                if(n->getAvlTree()->root != nullptr){
                    printSecondaryNodes(n->getAvlTree()->root, out);
                }
                else{
                    out+="{}\n";
                }
            }
            else{
                if(n->getRedBlackTree()->root != nullptr){
                    printSecondaryNodes(n->getRedBlackTree()->root, out);
                }
                else{
                    out+="{}\n";
                }
            }




            if(n->left != NULL){
                queue.push(n->left);
            }

            if(n->right != NULL){
                queue.push(n->right);
            }

            queue.pop();
            i++;

        }
    if(isSingleCategory) break;

    }
    out+="}\n";

}
//finding the named secondary node in primary node's tree and returns it.
SecondaryNode* BinarySearchTree::findSecondaryNode(SecondaryNode *node, string name) {
    if(node == nullptr || node->name == name){
        return node;
    }
    else if(name > node->name){
        return findSecondaryNode(node->right, name);
    }
    return findSecondaryNode(node->left, name);

}
//prints primary nodes  in levelorder.
//I used this function for both "printALlItems" and "printAllItemsInCategory".

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
//finding the secondary node and updating the data.
void BinarySearchTree::updateData(string primary,string secondary,int data,string treeName){
    PrimaryNode * primaryNode= search(root, primary);
    if(treeName=="AVL")findSecondaryNode(primaryNode->getAvlTree()->root, secondary)->data=data;
    else findSecondaryNode(primaryNode->getRedBlackTree()->root, secondary)->data=data;

}
//for "find" and "print" commands ,I create this function.

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
//prints the given secondary node's data and name
void BinarySearchTree::printSecondaryNodes(SecondaryNode *node, string &out) {
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
