//
// Created by umut on 23.12.2022.
//

#include "Model1.h"
#include "ReadFile.h"





void Model1::createModel1(string output1Name,string output2Name,vector<string> input) {
    ofstream  ofile;
    ofstream  ofile2;

    ofile.open("12.txt");
    ofile2.open("22.txt");


    string command;
    string output;
    string output2;
    BinarySearchTree model1=BinarySearchTree();
    BinarySearchTree model2=BinarySearchTree();



    for(string str:input){
        vector<string> split;
        stringstream ssin(str);
        while(ssin.good()){
            string line;
            getline(ssin,line,'\t');
            split.push_back(line);
        }

        if(split[0]=="insert"){
            PrimaryNode *node= model1.search(model1.root, split[1]);
            if(node== nullptr){
                model1.insert(split[1]);
                model2.insert(split[1]);

            }

            model1.search(model1.root, split[1])->getAvlTree()->insert(split[2], stoi(split[3]));
            model2.search(model2.root, split[1])->getRedBlackTree()->insert(split[2], stoi(split[3]));


        }
        else if(split[0]=="remove"){
            PrimaryNode *node= model1.search(model1.root, split[1]);
            PrimaryNode *node2= model2.search(model2.root, split[1]);
            node->getAvlTree()->deletion(split[2]);
            node2->getRedBlackTree()->deletion(split[2]);
        }
        else if(split[0]=="printAllItems") {
            model1.printAllItems(output, "all","AVL");
            model2.printAllItems(output2, "all","RBT");


        }
        else if(split[0]=="printAllItemsInCategory"){
            model1.printAllItems(output, split[1],"AVL");
            model2.printAllItems(output2, split[1],"RBT");


        }
        else if(split[0]=="updateData"){
            model1.updateData(split[1], split[2], stoi(split[3]),"AVL");
            model2.updateData(split[1], split[2], stoi(split[3]),"RBT");
        }
        else if(split[0]=="find"){
            model1.findPrintItems("find", output, split[1], split[2], "AVL");
            model2.findPrintItems("find", output2, split[1], split[2], "RBT");
        }
        else if(split[0]=="printItem"){
            model1.findPrintItems("printItem", output, split[1], split[2], "AVL");
            model2.findPrintItems("printItem", output2, split[1], split[2], "RBT");

        }


    }
    output.pop_back();
    output2.pop_back();

    ofile2<<output2;
    ofile<<output;
    ofile.close();
    ofile2.close();
}
