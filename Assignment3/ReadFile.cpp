//
// Created by umut on 12/2/22.
//

#include "ReadFile.h"
#include "iostream"
using namespace std;

ReadFile::ReadFile() {};
//I read the files and put them in vector.
vector<string> ReadFile::getData(string fileName) {
    ifile.open(fileName);
    if(ifile.is_open()){
        string line;
        while(getline(ifile,line)){
            data.push_back(line);
        }
    }
    return data;
}
