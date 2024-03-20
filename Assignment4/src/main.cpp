#include "Webstore.h"
int main(int argc, char **argv)
{

    Webstore model1= Webstore();
    model1.createWebStore(argv[1],argv[2], argv[3]);


    return 0;
}

