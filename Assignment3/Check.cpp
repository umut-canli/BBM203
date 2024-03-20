//
// Created by umut on 12/6/22.
//



#include "Check.h"
void Check::checkCashier(Cashier *cashiers, int cashierSize, vector<Customer> &customers, Queue &cashierQ, double *customer) {
    //Fİrstly the customer is created.
    customers.emplace_back(customers.size()+1,0,customer[0],0,customer[1],customer[2],customer[3]);
    //if cashier queue is not empty,firstly checks the cashier queue.
    if(cashierQ.size!=0){
        checkCashierQueue(cashiers, customers, cashierSize, cashierQ, customer[0]);
    }
    //First finds the cashier whose job is first done then checks if the customer's arrival time <= cashier's finish time
    //update the cashier and customer data.
    Employee *quickest= avaliableEmployee(cashiers, cashierSize, customer[0]);

    for(int i=0;i<cashierSize;i++){
        if(quickest!= nullptr){
            customers.back().setLeavingTime(customer[0]+customer[1]);
            customers.back().setCashierId(quickest->getID());
            quickest->setfinishTime(customer[0]+customer[1]);
            quickest->setbusyTime(customer[1]);
            return;
        }
    }
    //if there is no avaliable cashier for customer ,adds the customer to cashier queue.
    cashierQ.enQueueCashier(customers.back().getId(),customer[1],customer[2],customer[3]);
}

void Check::checkCashierQueue(Cashier *cashiers, vector<Customer> &customers, int cashierSize, Queue &cashierQ,
                              double currentTime) {
    //First finds the cashier whose job is first done then checks if the current >= cashier's finish time
    //the current time is updated according to the arrival time of each customer.
    for(int i=0;i<cashierSize;i++){
        Employee *quickestCashier= avaliableEmployee(cashiers, cashierSize, currentTime);
        if(quickestCashier!= nullptr){
            customers[cashierQ.front->ID-1].setLeavingTime(quickestCashier->getfinishTime() + cashierQ.front->orderTime);
            customers[cashierQ.front->ID-1].setCashierId(quickestCashier->getID());
            quickestCashier->setbusyTime(cashierQ.front->orderTime);
            quickestCashier->setfinishTime(quickestCashier->getfinishTime() + cashierQ.front->orderTime);
            cashierQ.deQueue();
        }
        if(cashierQ.size==0){
            return;
        }
    }


}

 //The same process as above is done here as well.
void Check::checkBarista(vector<Customer> &allCustomers, Customer &customer, Barista *barista, int baristaSize,
                         Queue &baristaQueue) {
    if(baristaQueue.size!=0){
        checkBaristaQueue(allCustomers,barista,baristaSize,baristaQueue,customer.getLeavingTime());
    }
    for(int i=0;i<baristaSize;i++){
        Employee *quickest= avaliableEmployee(barista, baristaSize, customer.getLeavingTime());
        if(quickest!= nullptr){
            customer.setExitTime(customer.getLeavingTime()+customer.getBrewTime());
            quickest->setfinishTime(customer.getLeavingTime()+customer.getBrewTime());
            quickest->setbusyTime(customer.getBrewTime());
            return;
        }
    }
    baristaQueue.enQueueBarista(customer.getId(),customer.getOrderTime(),customer.getBrewTime(),customer.getPrice());

}

void Check::checkBaristaQueue(vector<Customer> &allCustomers, Barista *barista, int baristaSize, Queue &baristaQueue,
                              double currentTime) {//TODO barista i düzenle
    for(int i=0; i < baristaSize; i++){
        Employee *quickest= avaliableEmployee(barista, baristaSize, currentTime);
        if(quickest!= nullptr){
            for(Customer &c:allCustomers){
                if(c.getId()==baristaQueue.front->ID){
                    c.setExitTime(c.getBrewTime()+quickest->getfinishTime());
                }
            }
            quickest->setbusyTime(baristaQueue.front->brewTime);
            quickest->setfinishTime(quickest->getfinishTime() + baristaQueue.front->brewTime);
            baristaQueue.deQueue();
        }
        if(baristaQueue.size==0){
            return;
        }
    }
}
//finds the avaliable Employee(cashier or barista) at currentTime.if there is no avaliable employee at currentTime returns nullptr.
Employee *Check::avaliableEmployee(Employee *employee, int employeeSize, double currentTime) {

    for(int i=0;i<employeeSize;i++){
        if(currentTime >= employee[i].getfinishTime()){
            return &employee[i];
        }

    }
    return nullptr;
}





