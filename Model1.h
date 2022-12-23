
//
// Created by umut on 23.12.2022.
//

#ifndef ASSGN4_MODEL1_H
#define ASSGN4_MODEL1_H
#include "string"
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "ReadFile.h"
#include "sstream"

using  namespace std;

class Model1 {
public:
    string file;

    explicit Model1(const string &file);

private:
    void createModel1(string input);
};


#endif //ASSGN4_MODEL1_H
