#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Rating.h"
#include "Member.h"
#include "Motorbike.h"
#include "Request.h"
#include "functions.h"

using namespace std;

Request::Request(int ID, int renterID, string bikeID, int day_rent, bool isApproved, bool isRejected) {
        this->requestID = ID;
        this->renterID = renterID;
        this->bike_rented_ID = bikeID;
        this->day_rented = day_rent;
        this->isApproved = isApproved;
        this->isRejected = isRejected;
}

Request::Request(){

}

string Request::toString()
{
    return to_string(requestID) + "," + to_string(renterID) + "," + bike_rented_ID + "," + to_string(day_rented) + "," + to_string(isApproved) + "," + to_string(isRejected);
}

string Request::display()
{
    return "Request ID: " + to_string(requestID) + "\nRenter: " + to_string(renterID) + "\nBike ID: " + bike_rented_ID + "\nDay(s) rent: " + to_string(day_rented) + "\nStatus: " + to_string(isApproved) + "\n----------------------------------\n\n";
}

int Request::getRenterID() {
    return this->renterID;
}

string Request::getBikeID(){
    return this->bike_rented_ID;
}

bool Request::getStatus(){
    return this->isApproved;
}

bool Request::getReject(){
    return this->isRejected;
}

int Request::getRequestID(){
    return this->requestID;
}

void Request::setApprove(bool isApproved){
    this->isApproved = isApproved;
}

void Request::setRejected(bool isRejected){
    this->isRejected = isRejected;
}

void Request::addNewRequest(Member member){
    vector<Request> requestlist = requestList();
    vector<Motorbike> availableMotor;
    vector<Motorbike> motorbikes = motorbikeList();

    for (Motorbike motor : motorbikes){
        if (motor.getOwnerID() != member.getID()){
            availableMotor.push_back(motor);
        }
    }

    if (availableMotor.size() > 0 ){
        string bikeID;
        cout << "Please enter license plate: ";
        cin >> bikeID;
        bool isRented = false;

        for (Request request: requestlist){
            if(request.getBikeID() == bikeID && request.isApproved){
                cout << "Bike has been already rented\n" << endl;
                isRented = true;
                break;
            } else if (request.getRenterID() == member.getID() && request.isApproved){
                cout <<"You have already rent a bike! Please return the old bike then try to send request again.\n\n";
                isRented = true;
                break;
            } else if (request.getRenterID() == member.getID() && request.getBikeID() == bikeID){
                cout <<"You have already send a request for this bike!\n\n";
                isRented = true;
                break;
            }
        }

        if (isRented){
            return;
        } else {
            cout << "Enter day rent: ";
            cin >> day_rented;

            Request newRequest(requestlist.size()+1, member.getID(), bikeID, day_rented, false, false);

            ifstream file("request.txt");
                if (file.is_open()){
                ofstream file("request.txt", ios::app);
                file << "\n" << newRequest.toString();
            } else {
                ofstream file("request.txt", ios::app);
                file << newRequest.toString();
            }
            file.close();

            requestlist.push_back(newRequest);
            cout << "Added successfully" << endl;   
        } 
    }
}    