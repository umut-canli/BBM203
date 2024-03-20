//
// Created by umut on 12/3/22.
//

#include "Employee.h"
Employee::Employee(int id) :busyTime(0),finishTime(0),id(id){}
int Employee::getID() {
    return id;
}

double Employee::getbusyTime() {
    return busyTime;
}
double Employee::getfinishTime() {
    return finishTime;
}
void Employee::setbusyTime(double  time) {
    busyTime+=time;
}


void Employee::setfinishTime(double time) {
    finishTime=time;
}

Employee::Employee() {
    busyTime=0;
    finishTime=0;
}

