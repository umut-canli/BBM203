//
// Created by umut on 20.12.2022.
//

#include "AVLNode.h"

AVLNode::AVLNode(string name, int data) : name(name), data(data) {
    left= nullptr;
    right= nullptr;
    height= 1;
}

AVLNode::AVLNode() {

}
