using namespace std;
#include "Model1.h"
#include "fstream"
#include "vector"
int main(int argc, char **argv)
{   ifstream ifile;
    vector<string> data;
    ifile.open("input1.txt");
    if(ifile.is_open()){
        string line;
        while(getline(ifile,line)){
            data.push_back(line);
        }
    }
    Model1 model1= Model1();
    model1.createModel1(argv[2],argv[3],data);


    return 0;
}

// This code is contributed by
// rathbhupendra
