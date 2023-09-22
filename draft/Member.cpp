#include <iostream>
#include <fstream>
#include <string>
#include "Member.h"
#include "Rating.h"
#include "Motorbike.h"
#include "Request.h"
#include "functions.h"
using namespace std;

Member::Member(int id, string name, string username, string password, string phoneNumber, string idType, string idNumber, string driverLicense, string expiredDate, double ratingScore, double creditPoint) {
    this->id = id; 
    this->name = name; 
    this->username = username; 
    this->password = password; 
    this->phoneNumber = phoneNumber;
    this->idType = idType;
    this->idNumber = idNumber;
    this->driverLicense = driverLicense;
    this->expiredDate = expiredDate;
    this->ratingScore = ratingScore;
    this->creditPoint = creditPoint;
};
Member::Member(){};

void Member::showInfo(){
    cout<<"Member Id: "<< id <<"\n";
    cout<<"Member's name: "<<name<<"\n\n"; 
}

void Member::ratingRenter(Member renter){
    int score;
    string cmt;
    
    cout<<"Enter score: ";
    cin>>score;
    cout<<"Enter comment: ";
    cin.ignore();
    getline(cin, cmt);

    Rating newRating(1, this->id, renter.id, score, cmt);
    renter.userRatingList.push_back(newRating);

    ifstream file("rating.txt");
    if (file.is_open()){
        ofstream file("rating.txt", ios::app);
        file << "\n" << newRating.getID() << "," << newRating.getCustomerID() << "," << newRating.getOwnerID() 
        << "," << newRating.getScore() << "," << newRating.getCmt();
    } else {
        ofstream file("renterRating.txt", ios::app);
        file << newRating.getID() << "," << newRating.getCustomerID() << "," << newRating.getOwnerID() 
        << "," << newRating.getScore() << "," << newRating.getCmt();
    }

    file.close();
}

void Member::setScore(){
    double total = 0;

    for (int i = 0; i < this->userRatingList.size(); i++){
        total += userRatingList[i].getScore();
    }

    this->ratingScore = (total/userRatingList.size());
}

int Member::getID(){
    return this->id;
}

double Member::getScore(){
    return this->ratingScore;
}

string Member::getName() {
    return this->name;
}

string Member::getUsername() {
    return this->username;
}

// Check if provided password matches the stored password
string Member::getPassword() {
    return this->password;
}


// Function to register a new customer
void Member::registerCustomer() {
    vector<Member> members = memberList();

    int id = generateId(members);
    double creditPoint = 20, ratingScore = 10;

    cout<<"-------------------REGISTER--------------------------\n";

    string fullname;
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, fullname);
    
    string phoneNumber;
    cout << "Enter your phone number: ";
    getline(cin, phoneNumber);

    string idType;
    cout << "Enter your ID type (passport / ID): ";
    getline(cin, idType);

    string idNumber;
    cout << "Enter your ID Number (passport / ID): ";
    getline(cin, idNumber);

    string driverLicense;
    cout << "Enter your driver license: ";
    getline(cin, driverLicense);

    string expiredDate;
    cout << "Enter the expired date of your driver license: ";
    getline(cin, expiredDate);

    string username;
    cout << "Enter your username: ";
    getline(cin, username);
    // Checking existing account
    for (Member& member : members){
        while (member.getUsername() == username)
        {
            cout << "The username has existed, enter another username: ";
            getline(cin, username);
        }
    }

    cout << "Enter your password: ";
    getline(cin, password);

    ifstream file("users.txt");
    if (file.is_open()){
        ofstream file("users.txt", ios::app);
        file << "\n" << id << "," << fullname << "," << username << "," << password << "," << phoneNumber << "," << idType << "," << idNumber << "," << driverLicense << "," << expiredDate << "," << ratingScore << "," << creditPoint;
    } else {
        ofstream file("users.txt", ios::app);
        file << id << "," << fullname << "," << username << "," << password << "," << phoneNumber << "," << idType << "," << idNumber << "," << driverLicense << "," << expiredDate << "," << ratingScore << "," << creditPoint;
    }
    file.close();

    cout << "Registration successful!!!! " << "\n" << fullname << "\nYour ID : " << id <<
    "\nYour credit point: "<< creditPoint << "\nYour rating score: "<< ratingScore << endl;

    cout << "-----------------------------------------------------\n";
}

Member *Member::loginCustomer(const string& username, const string& password)
{
    vector<Member> members = memberList();

    for (Member& member : members) {
        if (member.getUsername() == username && member.getPassword() == password) {
            return &member;
        }
    }
    return nullptr;
}

void Member::showSuitableBikes(){
    vector<Motorbike> motorbikes = motorbikeList();
    vector<Motorbike> sMotorbikes;

    for (Motorbike motor: motorbikes){
        if (motor.getOwnerID() != this->id && motor.getCredit() <= this->creditPoint && motor.getRequiredScore() <= this->ratingScore && !motor.isRent()){
            motor.showinfo();
            sMotorbikes.push_back(motor);
        }
    }

    if(sMotorbikes.size() == 0){
        cout<<"There is no bikes available! \n";
    }
}

vector<Request> Member::showRequest(){
    vector<Request> requestlist = requestList();
    vector<Request> requests;
    vector<Motorbike> motorbikes = motorbikeList();

    for (Motorbike motor : motorbikes){
        if (motor.getOwnerID() == this->id){
            for (Request request : requestlist){
                if (request.getBikeID() == motor.getID()) {
                    requests.push_back(request);
                }
            }
        }
    }

    if(requests.size() == 0){
        cout<<"There is no requests! \n";
    }

    return requests;
}