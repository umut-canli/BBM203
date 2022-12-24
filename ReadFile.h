//
// Created by umut on 23.12.2022.
//

#ifndef ASSGN4_READFILE_H
#define ASSGN4_READFILE_H
#include "iostream"
#include "fstream"
#include "vector"
using namespace std;
class ReadFile {
private:
    ifstream ifile;
    vector<string> data;
public:
    vector<string> getData();
    const vector<string> &getData1() const;

public:
    ReadFile(string fileName);


    vector<string> getData(string fileName);
};

#endif //ASSGN4_READFILE_H
