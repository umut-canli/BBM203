// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;
#include "AVLTree.h"
#include "RedBlackTree.h"
#include "ReadFile.h"
#include "BinarySearchTree.h"
#include "sstream"
#include "queue"
#include "fstream"
int main()
{
    ofstream  ofile;
    ofile.open("abc.txt");

    ReadFile read=ReadFile();

    string line;
    string command;
    string output;
    BinarySearchTree b=BinarySearchTree();
    vector<string> data=read.getData("input1.txt");

    for(string s:data){
        vector<string> split;
        stringstream ssin(s);
        while(ssin.good()){
            ssin>>line;
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
            output+="command:printAllItems\n{\n";

            b.print_order(b.root, output, false);
        }
        else if(split[0]=="printAllItemsInCategory"){
            PrimaryNode *node=b.Search(b.root,split[1]);
            output+="command:printAllItemsInCategory\t"+split[1]+"\n{\n";
            b.print_order(node, output, true);

        }
        else if(split[0]=="updateData"){
            PrimaryNode *node=b.Search(b.root,split[1]);
            b.findSecondaryNode(node->getTree()->root,split[2])->data= stoi(split[3]);

        }
        else{

            PrimaryNode *node=b.Search(b.root,split[1]);
            AVLNode *secNode= b.findSecondaryNode(node->getTree()->root,split[2]);
            if(split[0]=="find"){
                output+="command:find\t"+split[1]+"\t"+split[2]+"\n";
            }
            else{
                output+="command:printItem\t"+split[1]+"\t"+split[2]+"\n";
            }
            if(node== nullptr||secNode== nullptr){
                output+="{}\n";
                continue;
            }
            output+="{\n\""+node->name+"\":\n\t\""+split[2]+"\":\""+ to_string(secNode->data)+"\"\n}\n";

        }

   }

    cout<<output<<endl;

    return 0;
}

// This code is contributed by
// rathbhupendra
