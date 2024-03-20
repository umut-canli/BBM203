#include <iostream>
#include <fstream>
#include <string>
#include  <sstream>
#include <vector>
using namespace std;
string out="";
struct DoubleNode{ //initializing the double linkedlist
    DoubleNode *prev;
    DoubleNode *next;
    int id;
    int initial_bandwidth;
    int is_empty=0;
};
struct Node{// initializing the singly linkedlist
    string  apartment_name;
    int max_bandwidth;
    int size=0;
    Node *next;
    DoubleNode *flat;

};
typedef struct Node * nodeptr;
typedef struct DoubleNode * DNodeptr;
nodeptr tail= nullptr;
nodeptr head= nullptr;
nodeptr getNode (){
    nodeptr p;
    p=new Node;
    return p;
}
DNodeptr getDNode(){
    DNodeptr p;
    p= new DoubleNode;
    return p;
}

//insertAfter function is inserting the apartment after the given name.
void insertAfter(string *arr){
    nodeptr p=getNode();
    string apartName=arr[2].substr(6,1);
    //if there is no apartment
    if(head== nullptr){
        head=p;
        tail=p;
        head->next=head;
    }
    else{
        nodeptr curr=head;
        while(curr->apartment_name != apartName){
            curr=curr->next;
        }
        p->next=curr->next;
        curr->next=p;
        if(curr==tail) tail=p;
    }
    p->apartment_name=arr[1];
    p->flat= nullptr;
    p->max_bandwidth=stoi(arr[3]);
}
//insertBefore function is inserting the apartment before the given apartment
void insertBefore(string *arr){
    nodeptr p= getNode();
    string apartName=arr[2].substr(7,1);
    //if there is no apartment
    if(head==nullptr){
        head=p;
        tail=p;
        head->next=head;
    }
        // if there is one apartment
    else if(head==tail){
        p->next=head;
        tail->next=p;
        head=p;
    }
    else{
        nodeptr curr=head;
        while(curr->next->apartment_name!=apartName){
            curr=curr->next;
        }
        p->next=curr->next;
        curr->next=p;
        if(curr->next==head)head=p;
    }
    p->flat= nullptr;
    p->apartment_name=arr[1];
    p->max_bandwidth=stoi(arr[3]);
}
//findApartment function is finding the apartment in the linkedlist.

nodeptr findApartment(string apartName){
    nodeptr temp=head;
    do{
        if(temp->apartment_name==apartName)return temp;
        temp=temp->next;
    }
    while(temp!=head);
    return tail;
}
//
int calculateBandwidth(nodeptr apart, int initial_bandwith){
    DNodeptr headFlat=apart->flat;
    int total=0;
    if(headFlat== nullptr){
        if(apart->max_bandwidth<initial_bandwith){
            return  apart->max_bandwidth;
        }
        else{
            return initial_bandwith;
        }
    }
    while(headFlat!= nullptr){
        total+=headFlat->initial_bandwidth;
        headFlat=headFlat->next;
    }
    if(apart->max_bandwidth>total){

        if(apart->max_bandwidth-total<initial_bandwith){
            return apart->max_bandwidth-total;
        }
        else{
            return initial_bandwith;
        }

    }
    else{
        return 0;
    }


}
//lastFLat function is returning the given apartment's last flat.
DNodeptr lastFlat(DNodeptr headFlat){
    DNodeptr temp=headFlat;
    if(temp== nullptr){
        return nullptr;
    }
    else if(temp->next== nullptr){
        return temp;
    }
    while(temp->next!= nullptr){

        temp=temp->next;
    }
    return temp;

}
//findFlat function is returning the given apartment's flat
DNodeptr findFlat(DNodeptr head,int id){
    DNodeptr temp=head;
    if(head== nullptr){
        return nullptr;
    }
    else if(head->next== nullptr){
        return head;
    }
    else{
        while (temp!= nullptr){
            if(temp->id==id){
                return temp;
            }
            temp=temp->next;
        }
    }
    return nullptr;
}
//add flat function is adding the new flat to the given apartment.
void add_flat(string apartName,int position,int initial_bandwidth,int id){
    //finding the given apartment as a node.
    nodeptr apart= findApartment(apartName);
    DNodeptr p=getDNode();
    int maxBandWidth=calculateBandwidth(apart, initial_bandwidth);
    p->id=id;

    if( maxBandWidth< 0){
        p->is_empty=1;
        p->initial_bandwidth=0;
    }
    else{
        p->initial_bandwidth=maxBandWidth;
    }
    //if there is no flat in the apartment
    if(apart->flat== nullptr){
        apart->flat=p;
        p->next= nullptr;
        p->prev= nullptr;
    }

    else{
        DNodeptr temp=apart->flat;
        //if I need to add the new flat to "0" index .
        if(position==0){
            p->next=apart->flat;
            apart->flat->prev=p;
            apart->flat=p;
            p->prev= nullptr;
        }
        // if I need to add the new flat to the last index.
        else if(apart->size==position){
            temp= lastFlat(temp);
            temp->next=p;
            p->prev=temp;
            p->next= nullptr;
        }
        //if I need to add the new flat to somewhere in the middle
        else{
            //
            while(position-1>0){
                temp=temp->next;
                position--;
            }
            temp->next->prev=p;
            p->next=temp->next;
            p->prev=temp;
            temp->next=p;
        }
    }
    //increasing the flat number of apartment.
    apart->size++;
}

void make_flat_empty(string apartName,int id){
    //finding the given apart.
    nodeptr apart= findApartment(apartName);
    if(apart->size==1){
        apart->flat->is_empty=1;
        apart->flat->initial_bandwidth=0;
    }
    else{
        //if the flat number of given apart is more than 1 ,my code finds flat whose id is given and does some operations.
        DNodeptr temp=apart->flat;
        while(temp->id !=id){
            temp=temp->next;
        }
        temp->is_empty=1;
        temp->initial_bandwidth=0;
    }
}
int find_sum_of_max_bandwidth(){
    nodeptr temp=head;
    int sum=0;
    //if there is no apartment in the street.
    if(head== nullptr){
        return 0;
    }
    //if there is one apartment in the street.
    else if(head==tail){
        return head->max_bandwidth;
    }
    //if there is more than 1 apartment in the street.
    do{
        sum+=temp->max_bandwidth;
        temp=temp->next;
    }
    while(temp!=head);
    return sum;
}
//remove_flat function is removing the all flats of given apartment.
void remove_flat(nodeptr apart){
    //initializing 2 Double node pointer for the deleting operation.
    DNodeptr headFlat=apart->flat;
    DNodeptr temp=headFlat;
    // if there is no flat,we don't need to check.
    // if there is one flat just delete it and return.
    if(apart->size==0)return;
    else if(apart->size==1){
        delete apart->flat;
        apart->flat= nullptr;
    }
    //if there is more than 1 flat.
    else{
        while(temp!= nullptr){
            temp=temp->next;
            delete headFlat;
            headFlat=temp;
        }
        apart->flat= nullptr;
    }
}

void remove_apartment(string apartName){
    nodeptr temp=head;
    nodeptr del= findApartment(apartName);
    //Firstly,I deleted the all flats of the given apartments by using "remove_flat" function.
    remove_flat(del);
    if(head==tail){
        head= nullptr;
        tail= nullptr;
    }
    else if(head->next==tail) {
        if(del==head){
            head=tail;
        }
        else if(del==tail) {
            tail=head;
        }
    }
    else{
        //finding the previous apartment to be deleted and updating the apartment linkedlist.
        while(temp->next->apartment_name!=del->apartment_name){
            temp=temp->next;
        }
        temp->next=del->next;
        if(del==tail){
            tail=temp;
        }
        else if(del==head){
            head=head->next;
        }
    }
    delete del;

}
void merge_two_apartments(string first,string second){
    nodeptr firstApart= findApartment(first);
    nodeptr secondApart= findApartment(second);
    DNodeptr curr= lastFlat(firstApart->flat);
    //if the first apartment's size is 0,I just copy the second apartment's flats.
    if(firstApart->size==0){
        firstApart->flat=secondApart->flat;
        secondApart->flat= nullptr;
    }
    //if number of flats of the second apartment is 0,I don't need to do anything because it is empty.
    //Otherwise,I added the flat list of the second apartment to the flat list of the first apartment.
    else if(secondApart->size!=0){
        curr->next=secondApart->flat;
        secondApart->flat->prev=curr;
        secondApart->flat= nullptr;
    }
    //updating maxbandwith and size.
    firstApart->max_bandwidth+=secondApart->max_bandwidth;
    firstApart->size+=secondApart->size;
    secondApart->size=0;
    //deleting the second apartment.
    remove_apartment(second);

}
//tagFlat function is finding the given flat and tag that flat from the flat list and updating the flat list.
//I wrote this funtion because i wanted to use it for the "relocate" function
//Basically I pick the given flat and update the flat list without picked flat.After that I combine them in relocate apartment all at once

DNodeptr tagFlat(int id,nodeptr apart){
    DNodeptr  tempFlat=apart->flat;
    //if there is one apart , update the apart list,apart size and maxbandwidth
    if(apart->size==1){
        apart->flat= nullptr;
        apart->size--;
        apart->max_bandwidth-=tempFlat->initial_bandwidth;
        return tempFlat;
    }
    else{
        //if the given flat is the first flat i choose it and i delete from the list.I also update maxbandwidth and size Then i return it
        if(apart->flat->id==id){
            apart->flat=tempFlat->next;
            tempFlat->next->prev= nullptr;
            apart->size--;
            apart->max_bandwidth-=tempFlat->initial_bandwidth;
            return tempFlat;
        }
        else{
            //Otherwise,I find the given flat with iteration.Then i delete the flat i chose from list.
            while(tempFlat!= nullptr){
                if(tempFlat->id==id){
                    if(tempFlat->next== nullptr){  //if the chosen flat is the last flat of apartment
                        tempFlat->prev->next= nullptr;
                        tempFlat->prev= nullptr;
                        apart->size--;
                        apart->max_bandwidth-=tempFlat->initial_bandwidth;

                        return tempFlat;
                    }
                    else{
                        tempFlat->next->prev=tempFlat->prev;
                        tempFlat->prev->next=tempFlat->next;
                        tempFlat->next= nullptr;
                        tempFlat->prev= nullptr;

                    }
                    apart->size--;
                    apart->max_bandwidth-=tempFlat->initial_bandwidth;
                    return tempFlat;
                }
                tempFlat=tempFlat->next;
            }
        }
    }
    return nullptr;
}
//the function I wrote was for relocate function
//Relocate function has 3 steps.
//1.) I used vector to keep a list of flat's id to be replaced.So i am iterating these id s and I am finding the flats
void relocate(string apartName, int index, vector<int> vec){
    int count=0;
    //find the tempFlat I want to add on.
    nodeptr apart= findApartment(apartName);
    nodeptr temp=head;
    DNodeptr tempFlat;
    DNodeptr headOfnewFlats= nullptr;
    DNodeptr lastIndexOfFlats= nullptr;
    for(int i:vec){

        do{
            //I find the wanted tempFlat
            tempFlat=temp->flat;
            while(tempFlat != nullptr){
                if(tempFlat->id == i){
                    count++;
                    /* I Extract it by using "tagFlat" function .
                     * (extractFlat has no next or prev right now because as I said before "tagflat" function picking the chosen tempFlat and updating the flatlist of apartment)*/
                    DNodeptr extractFlat= tagFlat(tempFlat->id, temp);
                    //Burada ingilizcem yetmedi hocam kusura bakmayin
                    /* "headOfnewFlats" aslinda relocate etmek istedigimiz flatlarin headi.
                        ilk basta benim amacim tüm streeti iterate ederek istenilen flatlari bulma ve bunlarla yeni bir
                        linkedlist olusturmak ve tek seferde eklemek istedigimiz apartmana bu linkedlisti ekleme*/
                    if(headOfnewFlats== nullptr)headOfnewFlats=extractFlat;
                    else{
                        // headOfnewFlats inserting operations
                        if(headOfnewFlats->next== nullptr){
                            headOfnewFlats->next=extractFlat;
                            extractFlat->prev=headOfnewFlats;
                        }
                        else{
                            lastIndexOfFlats= lastFlat(headOfnewFlats);
                            lastIndexOfFlats->next=extractFlat;
                            extractFlat->prev=lastIndexOfFlats;
                        }
                    }
                    //updating apart maxbandwidth
                    apart->max_bandwidth+=extractFlat->initial_bandwidth;
                }

                tempFlat=tempFlat->next;
            }
            temp=temp->next;
        }
        while(temp!=head);
    }
    //After combining the flats we want to add under a single linkedlist,all i need to do is add them to the wanted apartment
    lastIndexOfFlats= lastFlat(headOfnewFlats);
    if(apart->size==0){
        apart->flat=headOfnewFlats;
    }
    else if(apart->size==1){
        lastIndexOfFlats->next=apart->flat;
        apart->flat->prev=lastIndexOfFlats;
        apart->flat=headOfnewFlats;
    }
    else{
        DNodeptr selectFlat= findFlat(apart->flat,index);
        if(selectFlat==apart->flat){
            apart->flat=headOfnewFlats;
            lastIndexOfFlats->next=selectFlat;
            selectFlat->prev=lastIndexOfFlats;
        }
        else{
            selectFlat->prev->next=headOfnewFlats;
            headOfnewFlats->prev=selectFlat->prev;
            selectFlat->prev=lastIndexOfFlats;
            lastIndexOfFlats->next=selectFlat;
        }
    }
    apart->size+=count;

}
//I created the string ("out") to record outputs before.
//output function
void output(nodeptr headApart, string &line){
    nodeptr p=headApart;
    do{
        DNodeptr d=p->flat;
        line+=p->apartment_name+"("+ to_string(p->max_bandwidth)+ ")\t";
        while (d!= nullptr){
            line+="Flat"+ to_string(d->id)+"("+ to_string(d->initial_bandwidth)+")\t";
            d=d->next;
        }
        line+="\n";
        p=p->next;

    }
    while(p != headApart);

    line+="\n";


}

int main(int argc, char *argv[]) {
    ofstream ofile;
    ifstream ifile;
    vector<int> vec;
    //input files are max 5 parts (for ex:  add_flat	X	0   25  1).So I created dynamic array with 5 index.
    string *com=new string [5];
    ifile.open(argv[1]);

    if(ifile.is_open()){
        string line;

        while(getline(ifile,line)){
            int i=0;
            stringstream ssin(line);
            while(ssin.good()&&i<5){
                ssin>>com[i];
                i++;
            }
            if(com[0]=="add_apartment"){
                if(com[2]=="head"){
                    nodeptr p=getNode();
                    head=p;
                    tail=p;
                    head->next=head;
                    p->flat= nullptr;
                    p->apartment_name=com[1];
                    p->max_bandwidth= stoi(com[3]);

                }
                else if(com[2].substr(0,5)=="after") {
                    insertAfter(com);
                }
                else{
                    insertBefore(com);
                }
            }
            else if(com[0]=="add_flat"){
                add_flat(com[1], stoi(com[2]), stoi(com[3]), stoi(com[4]));
            }else if(com[0]=="remove_apartment"){
                remove_apartment(com[1]);
            }else if(com[0]=="make_flat_empty"){
                make_flat_empty(com[1], stoi(com[2]));
            }else if(com[0]=="find_sum_of_max_bandwidths"){
                out+="sum of bandwidth: "+ to_string(find_sum_of_max_bandwidth())+"\n\n";

            }else if(com[0]=="merge_two_apartments"){
                merge_two_apartments(com[1],com[2]);
            }else if(com[0]=="list_apartments"){
                output(head,out);
            }else{
                stringstream sstr(com[3].substr(1,com[3].length()-2));
                while(sstr.good()){
                    string substr;
                    getline(sstr,substr,',');

                    vec.push_back(stoi(substr));
                }
                relocate(com[0], stoi(com[2]), vec);




            }
        }
    }
    //output.txt
    ofile.open(argv[2]);
    ofile<<out;
    ifile.close();
    ofile.close();



    return 0;
}
