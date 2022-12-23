//
// Created by umut on 23.12.2022.
//

#include "Model1.h"

void Model1::createModel1(string input) {
    ofstream  ofile;
    ofile.open("output23.txt");


    ReadFile read=ReadFile();
    RedBlackTree rbt=RedBlackTree();

    string command;
    string output;
    string output2;
    BinarySearchTree model1=BinarySearchTree();
    BinarySearchTree model2=BinarySearchTree();
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
            PrimaryNode *node=model1.Search(model1.root, split[1]);
            if(node== nullptr){
                model1.insert(split[1]);
                model2.insert(split[1]);

            }

            model1.Search(model1.root, split[1])->getAvlTree()->insert(split[2], stoi(split[3]));
            model2.Search(model2.root, split[1])->getRedBlackTree()->insert(split[2], stoi(split[3]));


        }
        else if(split[0]=="remove"){
            PrimaryNode *node=model1.Search(model1.root, split[1]);
            node->getAvlTree()->deletion(split[2]);
        }
        else if(split[0]=="printAllItems") {
            model1.printAllItems(output, "all","AVL");
            model2.printAllItems(output2, "all","RBT");


        }
        else if(split[0]=="printAllItemsInCategory"){
            model1.printAllItems(output, split[1],"AVL");
            model1.printAllItems(output2, split[1],"RBT");


        }
        else if(split[0]=="updateData"){
            model1.updateData(split[1], split[2], stoi(split[3]));
        }
        else if(split[0]=="find"){
            model1.find("find", output, split[1], split[2]);
        }
        else if(split[0]=="printItem"){
            model1.find("printItem", output, split[1], split[2]);

        }


    }
    output.pop_back();
    cout<<output2<<endl;
    ofile<<output;
    ofile.close();
}

Model1::Model1(const string &file) : file(file) {
    createModel1(file);
}
