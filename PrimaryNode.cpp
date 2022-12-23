//
// Created by umut on 19.12.2022.
//

#include "PrimaryNode.h"

PrimaryNode::PrimaryNode() {}

PrimaryNode::PrimaryNode(std::string  name)  {
    this->name=name;
    tree= new AVLTree();
    rbt=new RedBlackTree();
    left= nullptr;
    right= nullptr;
}

AVLTree *PrimaryNode::getTree() const {
    return tree;
}

RedBlackTree *PrimaryNode::getRbt() const {
    return rbt;
}
