//
// Created by umut on 12/4/22.
//

#include "Customer.h"



Customer::Customer(int id,int cashierID,double arrivalTime, double takeOrder, double orderTime, double brewTime, double price)
        : exitTime(0), id(id),cashierID(cashierID), arrivalTime(arrivalTime), leavingTime(takeOrder), orderTime(orderTime), brewTime(brewTime), price(price) {}

Customer::Customer() {}


int Customer::getId() const {
    return id;
}

double Customer::getExitTime()  {
    return exitTime;
}
double Customer::getArrivalTime() const {
    return arrivalTime;
}


double Customer::getLeavingTime() const {
    return leavingTime;
}



double Customer::getBrewTime() const {
    return brewTime;
}



double Customer::getPrice() const {
    return price;
}

double Customer::getOrderTime() const {
    return orderTime;
}

int Customer::getCashierId() const {
    return cashierID;
}



void Customer::setExitTime(double exitTime) {
    Customer::exitTime = exitTime;
}

void Customer::setLeavingTime(double leavingTime) {
    this->leavingTime=leavingTime;
}

void Customer::setCashierId(int cashierId) {
    cashierID = cashierId;
}
