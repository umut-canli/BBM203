//
// Created by umut on 20.12.2022.
//

#ifndef ASSGN4_READFILE_H
#define ASSGN4_READFILE_H


#include "vector"
#include "string"
#include "fstream"
using  namespace std;

class ReadFile {

    vector<string> data;
public:
    vector<string> getData();
    ReadFile(string txt);

};


#endif //ASSGN4_READFILE_H
