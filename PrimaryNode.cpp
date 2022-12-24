//
// Created by umut on 19.12.2022.
//

#include "PrimaryNode.h"


PrimaryNode::PrimaryNode(string  name)  {
    this->name=name;
    avlTree= new AVLTree();
    redBlackTree=new RedBlackTree();
    left= nullptr;
    right= nullptr;
}

AVLTree *PrimaryNode::getAvlTree()  {
    return avlTree;
}

RedBlackTree *PrimaryNode::getRedBlackTree()  {
    return redBlackTree;
}
