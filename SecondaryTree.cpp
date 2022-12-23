//
// Created by umut on 23.12.2022.
//

#include "SecondaryTree.h"
#include "queue"

void SecondaryTree::preOrder(SecondaryNode *root) {
    if(root== nullptr){
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
}

SecondaryNode *SecondaryTree::findMin(SecondaryNode *root) {
    if(root== nullptr){
        return root;
    }
    else if(root->left== nullptr){
        return root;
    }
    return findMin(root->left);
}

SecondaryNode *SecondaryTree::find(SecondaryNode *root, string name) {
    return nullptr;
}

void SecondaryTree::print_order(SecondaryNode *root, string &out) {
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
