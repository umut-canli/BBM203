//
// Created by umut on 12/2/22.
//
#include "Cashier.h"
#include "Node.h"
#include "Barista.h"
#include "string"
#include "Customer.h"
#include "vector"
#include "Queue.h"
#include "ReadFile.h"
#include "fstream"
#include "iostream"


using namespace std;
#ifndef ASSGN3_HUCOFFEESHOP_H
#define ASSGN3_HUCOFFEESHOP_H


class HUCoffeeShop {
public:
    HUCoffeeShop(string fileName,const string& outputName);
    void createModel1(Cashier *cashierss,vector<Customer> &customers,int maxCashierQueue,int numofOrders,int numofCashiers,ofstream &ofile);
    void createModel2(Cashier *cashiers,vector<Customer> &customers,int maxCashierQueue,int numofOrders,int numofCashiers,ofstream &ofile);

    Employee *quickestEmployee(Employee *employee, int employeeSize);
};


#endif //ASSGN3_HUCOFFEESHOP_H
