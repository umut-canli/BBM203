//
// Created by umut on 12/2/22.
//

#ifndef ASSGN3_READFILE_H
#define ASSGN3_READFILE_H
#include "iostream"
#include "fstream"
#include "vector"
using namespace std;
class ReadFile {
private:
    ifstream ifile;
    vector<string> data;
public:
    ReadFile();


    vector<string> getData(string fileName);
};


#endif //ASSGN3_READFILE_H