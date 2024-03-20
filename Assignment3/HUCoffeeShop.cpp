//
// Created by umut on 12/2/22.
//

#include "HUCoffeeShop.h"
#include "ReadFile.h"
#include "iomanip"
#include "string"
#include "vector"
#include "Barista.h"
#include "Customer.h"
#include "algorithm"
#include "Check.h"
#include "Cashier.h"
#include "Queue.h"
#include "iostream"
#include "sstream"
using namespace std;


HUCoffeeShop::HUCoffeeShop(string fileName,const string& outputName) {
    //First I read the data .("input.txt") and I initialized some variables.
    ReadFile read;
    double *lines=new double[4];

    vector<string> data=read.getData(fileName);
    vector<Customer> customers;
    int numOfOrders= stoi(data[1]);
    int numOfCashiers= stoi(data[0]);

    Cashier *cashiers = new Cashier[numOfCashiers];
    Queue cashierQ;
    Check check1;  //All the operations are done by the methods of this class.
    int maxCashierQ=cashierQ.size;
    ofstream ofile;
    ofile.open(outputName);
    ofile<<setprecision(2);
    ofile<<fixed;
    //Cashiers working principles are same for both models .


    for(int i=0;i<numOfCashiers;i++){
        cashiers[i]=Cashier(i + 1, 1);
    }
    //In here ,I send the customers to cashiers.
    for(int i=2;i<numOfOrders+2;i++){
        int count=0;
        stringstream ssin(data[i]);
        while(ssin.good()&&count<4){
            ssin>>lines[count];
            count++;
        }
        check1.checkCashier(cashiers, numOfCashiers, customers, cashierQ, lines);
        //finds the maximum cashier queue size.
        if(cashierQ.size > maxCashierQ){
            maxCashierQ=cashierQ.size;
        }
    }


    //After check all the customers , in here checks if there is any customer left in cashier queue.
   // if customer queue is not empty,sent customers to cashiers(to the cashier whose job is first done) and update the variables.
    while(cashierQ.size!=0){
        Employee *first= quickestEmployee(cashiers,numOfCashiers);
        for(Customer &c:customers){
            if(c.getId()==cashierQ.front->ID){
                c.setLeavingTime(first->getfinishTime()+c.getOrderTime());
            }
        }
        first->setfinishTime(first->getfinishTime()+cashierQ.front->orderTime);
        first->setbusyTime(cashierQ.front->orderTime);
        cashierQ.deQueue();
    }
    //After creating customers, I sort them by checkout time from the cashiers.So I can send them to baristas.
    sort(customers.begin(), customers.end(), [](const Customer &lhs, const Customer &rhs) {
        return lhs.getLeavingTime()< rhs.getLeavingTime();
    });
    //initializing model2customers for model2.
    vector<Customer> model2customers=customers;
    //Starting the barista parts for both models.
    createModel1(cashiers,customers,maxCashierQ,numOfOrders,numOfCashiers,ofile);
    createModel2(cashiers,model2customers,maxCashierQ,numOfOrders,numOfCashiers,ofile);

    ofile.close();





}



void HUCoffeeShop::createModel1(Cashier *cashierss,vector<Customer> &customers,int maxCashierQueue,int numofOrders,int numofCashiers,ofstream &ofile) {
    int m1MaxBaristaQ=0;
    double totalM1=0;
    Queue baristaQ;
    Check check;
    Barista *barista;
    barista=new Barista[numofCashiers/3];
    //initializing baristas with id's.
    for(int j=0;j<numofCashiers/3;j++){
        barista[j]=Barista(j+1);
    }


    //Checks parts for barista
    for(int i=0;i<customers.size();i++){
        check.checkBarista(customers, customers[i], barista, numofCashiers / 3, baristaQ);
        //updates the maximum barista queue size.
        if(baristaQ.size>m1MaxBaristaQ){
            m1MaxBaristaQ=baristaQ.size;
        }
    }


    //After check all the customers , in here I check if there is any customer left in barista queue.
   //if barista queue is not empty,I sent customers to barista(to the cashier whose job is first done) and update the variables.
    while(baristaQ.size!=0){
        Employee *first= quickestEmployee(barista, numofCashiers / 3);
        for(Customer &c:customers){
            if(c.getId()==baristaQ.front->ID){
                c.setExitTime(first->getfinishTime()+c.getBrewTime());
            }
        }
        first->setfinishTime(first->getfinishTime()+baristaQ.front->brewTime);
        first->setbusyTime(baristaQ.front->brewTime);
        baristaQ.deQueue();
    }
    //finds total time for model 1.(Which barista is finished last, that's the total time)
    for(int i=0;i<numofCashiers/3;i++){
        if(barista[i].getfinishTime()>totalM1){
            totalM1=barista[i].getfinishTime();
        }
    }
    //For the output part,I sort the customers by id.
    sort(customers.begin(), customers.end(), [](const Customer &lhs, const Customer &rhs) {
        return lhs.getId()< rhs.getId();
    });
    //Output part
    ofile<<totalM1<<endl;
    ofile<<maxCashierQueue<<endl;
    ofile<<m1MaxBaristaQ<<endl;
    for(int i=0;i<numofCashiers;i++){
        ofile<< cashierss[i].getbusyTime()/totalM1<<endl;
    }
    for(int i=0;i<numofCashiers/3;i++){
        ofile<<barista[i].getbusyTime()/totalM1<<endl;
    }
    for(Customer c:customers){
        ofile<< (c.getExitTime()-c.getArrivalTime())<<endl;
    }
    ofile<<endl;




}
void HUCoffeeShop::createModel2(Cashier *cashiers,vector<Customer> &customers,int maxCashierQueue,int numofOrders,int numofCashiers,ofstream &ofile) {
    double totalTimeM2=0;
    Barista *model2Barista=new Barista[numofCashiers / 3];
    Queue *allbaristaQ;
    int *maxBaristaQSize;
    allbaristaQ=new Queue[numofCashiers/3];
    Check check1;
    maxBaristaQSize=new int[numofCashiers / 3];
    //initializing model2Barista queues.

    for(int j=0;j<numofCashiers/3;j++){
        allbaristaQ[j]=Queue();
    }
    //In the begining , all of the sizes of model2Barista queues is 0.
    for(int i=0;i<numofCashiers/3;i++){
        maxBaristaQSize[i]=0;
    }
    //To check the customers, I send them with the model2Barista and model2Barista queue parameters that they are suitable for the checkBarista method
    for(int i=0;i<customers.size();i++){
        check1.checkBarista(customers, customers[i], &model2Barista[(customers[i].getCashierId() - 1) / 3], 1, allbaristaQ[(customers[i].getCashierId() - 1) / 3]);
        if(maxBaristaQSize[(customers[i].getCashierId() - 1) / 3] < allbaristaQ[(customers[i].getCashierId() - 1) / 3].size){
            maxBaristaQSize[(customers[i].getCashierId() - 1) / 3]=allbaristaQ[(customers[i].getCashierId() - 1) / 3].size;
        }
    }
    //After check all the customers , in here I check if there is any customer left in model2Barista queue.
    //if model2Barista queue is not empty,I sent customers to model2Barista and update the variables.
    for(int i=0;i<numofCashiers/3;i++){
        while(allbaristaQ[i].size!=0){
            for(Customer &c:customers){
                if(c.getId()==allbaristaQ[i].front->ID){
                    c.setExitTime(model2Barista[i].getfinishTime() + c.getBrewTime());
                }
            }
            model2Barista[i].setfinishTime(model2Barista[i].getfinishTime() + allbaristaQ[i].front->brewTime);
            model2Barista[i].setbusyTime(allbaristaQ[i].front->brewTime);
            allbaristaQ[i].deQueue();
        }

    }
    //finds total time for model 2.(Which model2Barista is finished last, that's the total time)

    for(int i=0;i<numofCashiers/3;i++){
        if(model2Barista[i].getfinishTime() > totalTimeM2){
            totalTimeM2=model2Barista[i].getfinishTime();
        }
    }
    //For the output part,I sort the customers by id.

    sort(customers.begin(), customers.end(), [](const Customer &lhs, const Customer &rhs) {
        return lhs.getId()< rhs.getId();
    });

    //output part
    ofile<<totalTimeM2<<endl;
    ofile<<maxCashierQueue<<endl;
    for(int i=0;i<numofCashiers/3;i++){
        ofile << maxBaristaQSize[i] << endl;
    }
    for(int i=0;i<numofCashiers;i++){
        ofile<< cashiers[i].getbusyTime()/totalTimeM2<<endl;
    }
    for(int i=0;i<numofCashiers/3;i++){
        ofile << model2Barista[i].getbusyTime() / totalTimeM2 << endl;
    }
    for(Customer c:customers){
        ofile<< (c.getExitTime()-c.getArrivalTime())<<endl;
    }
}

Employee *HUCoffeeShop::quickestEmployee(Employee *employee, int employeeSize) {
    Employee *quickest=&employee[0];
    for(int i=0;i<employeeSize;i++){
        if(employee[i].getfinishTime()<quickest->getfinishTime()){
            quickest=&employee[i];
        }
    }
    return quickest;

}





