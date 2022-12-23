//
// Created by umut on 19.12.2022.
//

#include "BinarySearchTree.h"
#include <iostream>
#include <queue>
using namespace std;


PrimaryNode *BinarySearchTree::createNode(string name) {
    PrimaryNode *node=new PrimaryNode(name);
    return node;
}

BinarySearchTree::BinarySearchTree() {
    root= nullptr;

}

void BinarySearchTree::insert2(PrimaryNode* &root,string name) {
    if(root== nullptr){
        root= createNode(name);
    }
    else if(name>root->name){
        insert2(root->right,name);
    }
    else if(name<root->name){
        insert2(root->left,name);
    }
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
void BinarySearchTree::printGivenLevel( PrimaryNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1) {
        cout<<"\""<<root->name<<"\":"<<endl;
        printLevelOrder(root->getTree()->root);

    }

    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}


void BinarySearchTree::printLevelOrder(PrimaryNode *root) {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++) {
            printGivenLevel(root, i);
            printf("\n");
        }

}

int BinarySearchTree::height(PrimaryNode *root) {
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
    }
}

void BinarySearchTree::printLevelOrder(AVLNode *root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        printGivenLevel1(root, i);
        printf("\n");
    }
}

int BinarySearchTree::height(AVLNode *root) {
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

void BinarySearchTree::printGivenLevel1(AVLNode *root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        cout<<"\t\""<<root->name<<"\":"<<"\""<<root->data<<"\"";
    else if (level > 1) {
        printGivenLevel1(root->left, level - 1);
        printGivenLevel1(root->right, level - 1);
    }
}

bool BinarySearchTree::printLevel(PrimaryNode *node, int level) {
    if (root == nullptr) {
        return false;
    }

    if (level == 1)
    {
        cout << root->name << " ";

        // return true if at least one node is present at a given level
        return true;
    }

    bool left = printLevel(root->left, level - 1);
    bool right = printLevel(root->right, level - 1);

    return left || right;
}

void BinarySearchTree::levelOrder(PrimaryNode *root) {
    int level = 1;

    // run till printLevel() returns false
    while (printLevel(root, level)) {
        level++;
    }
}
void BinarySearchTree::levelorder_traversal(PrimaryNode *root,string &out,bool isprintAll){
    queue <PrimaryNode*> primaryQueue;
    queue<AVLNode*> avlQueue;
    PrimaryNode *item;
    primaryQueue.push(root); //insert the root at first
    while(!primaryQueue.empty()){
        item = primaryQueue.front(); //get the element from the front end
        avlQueue.push(item->getTree()->root);
        cout << item->name << " ";

        if(!isprintAll){
            out+=root->name+"\n{\n\""+root->name+"\":";
            if(root->getTree()== nullptr){
                out+="{}";
            }

            else{
                root->getTree()->levelorder_traversal(root->getTree()->root,out);
            }
            out+="\n}\n";
            break;
        }
//command:printAllItems
//{
//"music":
//	"drum":"250"
//	"bass":"200","guitar":"150"
//	"piano":"300"
//"food":
//	"nachos":"55"
//	"fish":"30","tacos":"60"
//}
        else{
            out+="{\n\""+root->name+"\":";
            if(root->getTree()== nullptr){
                out+="{}";
            }
            else{
                root->getTree()->levelorder_traversal(root->getTree()->root,out);

            }
            out+="\n}\n";
        }
        if(item->left != NULL) //When left child is present, insert into queue
            primaryQueue.push(item->left);
        if(item->right != NULL) //When right child is present, insert into queue
            primaryQueue.push(item->right);
        primaryQueue.pop(); //remove the item from queue
    }
}

void BinarySearchTree::print_order(PrimaryNode *root,string &out,bool isSingleCategory) {
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
            if(n->getTree()->root!= nullptr){
                n->getTree()->print_order(n->getTree()->root,out);
            }
            else{
                out+="{}\n";
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
AVLNode *BinarySearchTree::findSecondaryNode(AVLNode *root, string name) {
    if(root== nullptr ||root->name==name){
        return root;
    }
    else if(name>root->name){
        return findSecondaryNode(root->right, name);
    }
    return findSecondaryNode(root->left, name);

}

