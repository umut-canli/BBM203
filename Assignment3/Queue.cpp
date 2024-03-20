//
// Created by umut on 12/2/22.
//
using namespace std;
#include "iostream"
#include "Queue.h"
Queue::Queue() {
    size=0;
    front=rear= NULL;
}

void Queue::deQueue() {
    Node *temp=front;
    if(temp== NULL){
        return ;
    }
    else if(front==rear){
        front= NULL;
        rear= NULL;
    }
    else{
        front=front->next;
    }
    delete temp;
    size--;
}


//In here,I wrote two enqueue methods for each baristaQueue and cashierQueue.

//in enQueueCashier ,I didn't need to check the price .So I just added the nodes.
void Queue::enQueueCashier(int ID,double orderTime,double brewTime,double price) {
    Node *temp=new Node(ID,brewTime,orderTime,price);
    if(rear== NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    size ++;
}
//For the enQueueBarista ,I need to sort the nodes by their prices.So I find the correct position for node.
void Queue::enQueueBarista(int ID,double orderTime,double brewTime ,double price) {
    Node *temp=new Node(ID,brewTime,orderTime,price);
    if(rear== nullptr){
        front= temp;
        rear= temp;
    }
    else{
        Node *curr=front;
        if(temp->price>front->price){
            temp->next=front;
            front=temp;
        }
        else if(rear->price>temp->price){
            rear->next=temp;
            rear=temp;
        }
        else{
            while(curr->next!= nullptr){
                if((temp->price)>(curr->next->price)){
                    temp->next=curr->next;
                    curr->next=temp;
                    break;
                }
                curr=curr->next;
            }
        }
    }
    size++;
}
