//
// Created by umut on 20.12.2022.
//

#include "ReadFile.h"

vector<string> ReadFile::getData() {
    return data;
}
//Reading the input files into vector<string> data
ReadFile::ReadFile(string fileName){
    ifstream  ifile;
    ifile.open(fileName);
    if(ifile.is_open()){
        string  line;
        while(getline(ifile,line)){
            data.push_back(line);
        }
    }
}