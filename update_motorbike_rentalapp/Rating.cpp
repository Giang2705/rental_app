#include <iostream>
#include "Rating.h"
#include "Member.h"

using namespace std;

Rating::Rating(int id, int owner, int customer, int score, string cmt) {this->id = id; this->ownerID = owner; this->customerID = customer ;this->score = score, this->cmt = cmt;}

//function to present the ratings
void Rating::displayDetail(){
    cout<<"Owner's ID: "<<ownerID<<"\n";
    cout<<"Customer's ID: "<<customerID<<"\n";
    cout<<"Rating ID: "<< id <<"\n";
    cout<<"Rating's score: "<<score<<"\n";
    cout<<"Rating's comment: "<<cmt<<"\n\n";
};

//structures
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
