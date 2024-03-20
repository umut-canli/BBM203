//
// Created by umut on 12/3/22.
//

#ifndef ASSGN3_EMPLOYEE_H
#define ASSGN3_EMPLOYEE_H


class Employee {
private:
    int id;
    double busyTime;
    double finishTime;
public:
    Employee(int id);
    int getID();
    double getbusyTime();
    double getfinishTime();
    void setfinishTime(double time);
    void setbusyTime(double time);


    Employee();
};



#endif //ASSGN3_EMPLOYEE_H
