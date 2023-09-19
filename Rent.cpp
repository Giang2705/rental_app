#include <iostream>
#include <vector>
#include <ctime>
#include "Member.h"
#include "Motorbike.h"
#include "datalist.h"
using namespace std;

class Rent{
    private:
    int requestID;
    vector <Member> renter;
    vector <Motorbike> bike_rented;
    int day_rented;
    public:
    Rent(int requestID = 0, vector <Member> renter = {}, vector <Motorbike> bike_rented = {}, int day_rented = 0) 
    : requestID(requestID), renter(renter), bike_rented(bike_rented), day_rented(day_rented){}

    void rent_time();
    int total_amount();
    int billinvoice();
};

void Rent :: rent_time(){
    time_t now = time(0); // get current dat/time with respect to system  
    char* rent_date = ctime(&now); // convert it into string  
    cout << "Rent date and time is: " << rent_date << endl; // print local date and time  
}

void Rent :: return_time(){
    time_t return_date = time(0) + day_rented;
    char* rd = ctime(&return_date);
    cout << "Return date and time is: " << rd << endl;
} 

int Rent :: total_amount(){
    int fee = 0;
    cout << "Please enter day of renting: ";
    cin >> day_rented;
    fee = day_rented * 150;
    cout << "The amount is: " << fee;
}

int Rent :: billinvoice(){
    rent_time();
}