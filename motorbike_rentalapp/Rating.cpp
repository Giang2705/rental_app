#include <iostream>
#include "Rating.h"
#include "Member.h"

using namespace std;

//Parameterized constructor
Rating::Rating(int id, int customer, int owner, int score, string cmt) {this->id = id; this->customerID = customer; this->ownerID = owner ;this->score = score, this->cmt = cmt;}

void Rating::displayDetail(){ //display the rating of each member
    cout<<"Owner's ID: "<<ownerID<<"\n";
    cout<<"Customer's ID: "<<customerID<<"\n";
    cout<<"Rating ID: "<< id <<"\n";
    cout<<"Rating's score: "<<score<<"\n";
    cout<<"Rating's comment: "<<cmt<<"\n\n";
};

int Rating::getOwnerID(){
    return this->ownerID;
};

int Rating::getCustomerID(){
    return this->customerID;
};

int Rating::getID(){
    return this->id;
};

int Rating::getScore(){
    return this->score;
};

string Rating::getCmt(){
    return this->cmt;
};
