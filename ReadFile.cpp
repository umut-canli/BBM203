//
// Created by umut on 23.12.2022.
//

#include "ReadFile.h"
#include "iostream"
using namespace std;


ReadFile::ReadFile(string fileName) {
    ifile.open(fileName);
    if(ifile.is_open()){
        string line;
        while(getline(ifile,line)){
            data.push_back(line);
        }
    }
}



vector<string> ReadFile::getData() {
    return data;
}

