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

// default constructor
Request::Request(int ID, int renterID, string bikeID, int day_rent, bool isApproved) {
        this->requestID = ID;
        this->renterID = renterID;
        this->bike_rented_ID = bikeID;
        this->day_rented = day_rent;
        this->isApproved = isApproved;
}

// default constructor
Request::Request(){

}

// turn information into string
string Request::toString()
{
    return to_string(requestID) + "," + to_string(renterID) + "," + bike_rented_ID + "," + to_string(day_rented) + "," + to_string(isApproved);
}

// structure
int Request::getRenterID() {
    return this->renterID;
}
// structure
string Request::getBikeID(){
    return this->bike_rented_ID;
}
// structure
bool Request::getStatus(){
    return this->isApproved;
}
// 
void Request::addNewRequest(Member member){
    vector<Request> requestlist = requestList();
    string bikeID;
    cout << "Please enter license plate: ";
    cin >> bikeID;
    bool isRented = false;

    for (Request request: requestlist){
        if(request.getBikeID() == bikeID && request.isApproved){
            cout << "Bike already exist" << endl;
            isRented = true;
            break;
        }
    }

    if (isRented){
        return;
    } else {
        cout << "Enter day rent: ";
        cin >> day_rented;

        Request newRequest(member.getID(), 1, bikeID, day_rented, false);

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

