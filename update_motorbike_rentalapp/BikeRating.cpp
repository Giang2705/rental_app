#include <iostream>
#include "BikeRating.h"
#include "Member.h"
#include "Motorbike.h"

using namespace std;

BikeRating::BikeRating(int customer, string bikeID, double score, string cmt) {this->customerID = customer; this->bikeID = bikeID ;this->score = score, this->cmt = cmt;}
BikeRating::BikeRating(){}

// display bike rating detail
void BikeRating::displayDetail(){
    cout<<"Customer's ID: "<<customerID<<"\n";
    cout<<"Bike ID: "<< bikeID <<"\n";
    cout<<"Rating's score: "<<score<<"\n";
    cout<<"Rating's comment: "<<cmt<<"\n\n";
};


// constructors
int BikeRating::getCustomerID(){
    return this->customerID;
};

string BikeRating::getBikeID(){
    return this->bikeID;
};

double BikeRating::getScore(){
    return this->score;
};

string BikeRating::getCmt(){
    return this->cmt;
};

void BikeRating::setCustomerID(int id){
    this->customerID = id;
}

void BikeRating::setBikeID(string bikeID){
    this->bikeID = bikeID;
}

void BikeRating::setScore(double score){
    this->score = score;
}

void BikeRating::setCmt(string cmt){
    this->cmt = cmt;
}
