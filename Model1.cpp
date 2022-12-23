//
// Created by umut on 23.12.2022.
//

#include "Model1.h"

void Model1::createModel1(string input) {
    ofstream  ofile;
    ofile.open("output23.txt");

    ReadFile read=ReadFile();

    string command;
    string output;
    BinarySearchTree b=BinarySearchTree();
    vector<string> data=read.getData("input2.txt");

    for(string s:data){
        vector<string> split;
        stringstream ssin(s);
        while(ssin.good()){
            string line;
            getline(ssin,line,'\t');
            split.push_back(line);
        }

        if(split[0]=="insert"){
            PrimaryNode *node=b.Search(b.root,split[1]);
            if(node== nullptr){
                b.insert(split[1]);

            }

            b.Search(b.root,split[1])->getTree()->insert(split[2], stoi(split[3]));
        }
        else if(split[0]=="remove"){
            PrimaryNode *node=b.Search(b.root,split[1]);
            node->getTree()->deletion(split[2]);
        }
        else if(split[0]=="printAllItems") {
            b.printAllItems(output,"all");

        }
        else if(split[0]=="printAllItemsInCategory"){
            b.printAllItems(output, split[1]);


        }
        else if(split[0]=="updateData"){
            b.updateData(split[1],split[2], stoi(split[3]));
        }
        else if(split[0]=="find"){
            b.find("find",output,split[1],split[2]);
        }
        else if(split[0]=="printItem"){
            b.find("printItem",output,split[1],split[2]);

        }

    }
    output.pop_back();
    ofile<<output;
    cout<<output<<endl;
    ofile.close();
}

Model1::Model1(const string &file) : file(file) {
    createModel1(file);
}
