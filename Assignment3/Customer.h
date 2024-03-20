//
// Created by umut on 12/4/22.
//

#ifndef ASSGN3_CUSTOMER_H
#define ASSGN3_CUSTOMER_H
#include "Cashier.h"

class Customer {

private:
    int id;
    int cashierID;
    double arrivalTime;
    double orderTime;
    double brewTime;
    double price;
    double exitTime;
    double leavingTime;




public:

    Customer(int id,int cashierID,double arrivalTime, double totalTime, double orderTime, double brewTime, double price);
    Customer();

    void setExitTime(double exitTime);
    void setLeavingTime(double leavingTime);
    void setCashierId(int cashierId);

    int getCashierId() const;
    int getId() const;
    double getArrivalTime() const;
    double getLeavingTime() const;
    double getExitTime() ;
    double getBrewTime() const;
    double getOrderTime() const;
    double getPrice() const;




};


#endif //ASSGN3_CUSTOMER_H
