//
// Created by umut on 12/6/22.
//

#ifndef ASSGN3_CHECK_H
#define ASSGN3_CHECK_H
#include "Queue.h"
#include "Cashier.h"
#include "Customer.h"
#include "vector"
#include "Barista.h"
using namespace std;

class Check {
public:
     void checkCashier(Cashier *cashiers, int cashierSize, vector<Customer> &customers, Queue &cashierQ, double *customer);
     void checkCashierQueue(Cashier *cashiers, vector<Customer> &customers, int cashierSize, Queue &cashierQ, double currentTime);
     void checkBarista(vector<Customer> &allCustomers, Customer &customer, Barista *barista, int baristaSize, Queue &baristaQueue);
     void checkBaristaQueue(vector<Customer> &allCustomers, Barista *barista, int baristaSize, Queue &baristaQueue, double currentTime);
     Employee *avaliableEmployee(Employee *employee, int employeeSize, double currentTime);

};


#endif //ASSGN3_CHECK_H
