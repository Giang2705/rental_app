#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Member.h"
#include "functions.h"
using namespace std;

//constructors
Member::Member(int id, string name, string username, string password, string phoneNumber, string idType, string idNumber, string driverLicense, string expiredDate, double ratingScore, double creditPoint, bool isAdmin) {
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
    this->isAdmin = isAdmin;
};
Member::Member(){};

//display user's information
void Member::showInfo(){
    cout<<"Member Id: "<< id <<"\n";
    cout<<"Member's name: "<<name<<"\n"; 
    cout<<"Phone number: "<<phoneNumber<<"\n";
    cout<<"ID type: "<<phoneNumber<<"\n";
    cout<<"ID/Passport number: "<<phoneNumber<<"\n";
    cout<<"Driver license: "<<phoneNumber<<"\n";
    cout<<"Expired date: "<<phoneNumber<<"\n";
    cout<<"Credit: "<<phoneNumber<<"\n";
    cout<<"Rating score: "<<phoneNumber<<"\n\n";
    cout<<"-------------------------\n";
}

//display own rating list
void Member::showOwnRatingList(){
    vector<Rating> ratings = renterRatingList();
    vector<Rating> ownRatings;


    for (Rating r : ratings){
        if (r.getCustomerID() == this->id){
            ownRatings.push_back(r);
        }
    }

    if (ownRatings.size() == 0){
        cout<<"There is no rating to you!\n\n";
    } else {
        cout<<"-------------------OWN RATINGS LIST---------------------------\n";
        for (Rating r : ownRatings){
            r.displayDetail();
            cout<<"------------------------\n\n";
        }
    }
}

// display own bike rating list
void Member::showBikeRatingList(){
    vector<BikeRating> bikeRatings = bikeRatingList();
    vector<BikeRating> ownBikeRatings;
    vector<Motorbike> motorbikes = motorbikeList();

    for (BikeRating br : bikeRatings){
        for (Motorbike m : motorbikes){
            if (br.getBikeID() == m.getID() && m.getOwnerID() == this->id){
                ownBikeRatings.push_back(br);
            }
        }
    }

    if (ownBikeRatings.size() == 0){
        cout<<"There is no rating to your bike!\n\n";
    } else {
        cout<<"-------------------OWN BIKE RATINGS LIST---------------------------\n";
        for (BikeRating br : ownBikeRatings){
            br.displayDetail();
            cout<<"------------------------\n\n";
        }
        
        string choice;
        cout<<"Do you want to rating renter? (y/n): ";
        cin.ignore();
        getline(cin,choice);

        if(choice == "y"){
            int renterID;
            Member renter;
            vector<Member> members = memberList();

            cout<<"Enter the id of renter who you want to rate: ";
            cin>>renterID;

            for (Member m : members){
                if(m.getID() == renterID){
                    renter = m;
                    break;
                }
            }
            if(renter.getName() != ""){
                this->ratingRenter(renter);
            } else {
                cout<<"Renter does not exist! \n\n";
            }
        }
    }
}

// Rate renter
void Member::ratingRenter(Member renter){
    vector<Rating> ratings = renterRatingList();

    int score;
    string cmt;
    
    cout<<"Enter score: ";
    cin>>score;
    cout<<"Enter comment: ";
    cin.ignore();
    getline(cin, cmt);

    Rating newRating(ratings.size()+1, this->id, renter.id, score, cmt);

    ifstream file("RatingRenter.txt");
    if (file.is_open()){
        ofstream file("RatingRenter.txt", ios::app);
        file << "\n" << newRating.getID() << "," << newRating.getCustomerID() << "," << newRating.getOwnerID() 
        << "," << newRating.getScore() << "," << newRating.getCmt();
    } else {
        ofstream file("RatingRenter.txt", ios::app);
        file << newRating.getID() << "," << newRating.getCustomerID() << "," << newRating.getOwnerID() 
        << "," << newRating.getScore() << "," << newRating.getCmt();
    }

    file.close();
}


// Rate bike
void Member::ratingBike(string bikeID){
    vector<Motorbike> motorbikes = motorbikeList();
    vector<BikeRating> bikeRatings = bikeRatingList();
    Motorbike motor;

    for (Motorbike m : motorbikes){
        if (m.getID() == bikeID){
            motor = m;
            break;
        }
    }
    if (motor.getID() != ""){
        int score;
        string cmt;
        
        cout<<"Enter score: ";
        cin>>score;
        cout<<"Enter comment: ";
        cin.ignore();
        getline(cin, cmt);

        BikeRating newRating(this->id, motor.getID(), score, cmt);

        ifstream file("RatingBike.txt");
        if (file.is_open()){
            ofstream file("RatingBike.txt", ios::app);
            file << "\n" << newRating.getCustomerID() << "," << newRating.getBikeID() << "," << newRating.getScore() << "," << newRating.getCmt();
        } else {
            ofstream file("RatingBike.txt", ios::app);
            file << newRating.getCustomerID() << "," << newRating.getBikeID() << "," << newRating.getScore() << "," << newRating.getCmt();
        }
        file.close();
    } else {
        cout<<"Bike does not exist.";
    }
}


//setter & getter
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

bool Member::admin(){
    return this->isAdmin;
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

// login
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


//list suitable bikes
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


// list of requests
void Member::showRequest(){
    vector<Request> requestlist = requestList();
    vector<Request> requests;
    vector<Motorbike> motorbikes = motorbikeList();

    for (Motorbike motor : motorbikes){
        if (motor.getOwnerID() == this->id){
            for (Request request : requestlist){
                if (request.getBikeID() == motor.getID()) {    
                    cout<<request.display();
                    requests.push_back(request);
                }
            }
        }
    }

    if(requests.size() == 0){
        cout<<"There is no requests! \n";
    } else {
        string choice;

        cout << "Do you want to update the request? (y/n): ";
        cin.ignore();
        getline(cin,choice);

        if (choice == "y"){
            int requestID;
            cout<<"Please enter id of the request you want to update: ";
            cin>>requestID;
                
            approveRequest(requestID);
        }    
    }
}


// approving request
void Member::approveRequest(int inputID){
    ifstream request("request.txt");

    if (request.is_open()){
        int temp, requestID, renterID, day_rent;
        string bikeID, myString, line;
        bool isApproved;
        bool isRejected = false;

        while(getline(request, line)){
            stringstream ss(line);
            getline(ss, myString, ',');
            requestID = stoi(myString);
            getline(ss, myString, ',');
            renterID = stoi(myString);
            getline(ss, bikeID, ',');
            getline(ss, myString, ',');
            day_rent = stoi(myString);
            getline(ss, myString, ',');
            temp = stoi(myString);

            if (temp == 0){
                isApproved = false;
            } else {
                isApproved = true;
            }

            Request newRequest(requestID, renterID, bikeID, day_rent, isApproved, isRejected);

            if (newRequest.getRequestID() == inputID){
                string choice;
                
                cout<<"Do you want to approve this request? (y/n): ";
                cin.ignore();
                getline(cin,choice);

                if (choice == "y"){
                    newRequest.setApprove(true);
                    cout<<"Request is update!\n";
                }
            }

            ifstream file("new.txt");
            if (file.is_open()){
                ofstream file("new.txt", ios::app);
                file << "\n" << newRequest.toString();
            } else {
                ofstream file("new.txt", ios::app);
                file << newRequest.toString();
            }
        }
        request.close();
    }

    remove("request.txt");
    rename("new.txt", "request.txt");
    rejectRequest();
}


//reject request
void Member::rejectRequest(){
    vector<Request> requestlist = requestList();
    vector<Request> rejectedRequestList;

    for (Request approvedRequest : requestlist){
        if (approvedRequest.getStatus()){
            for (Request rejectedRequest : requestlist){
                if (approvedRequest.getRequestID() != rejectedRequest.getRequestID() && (approvedRequest.getBikeID() == rejectedRequest.getBikeID() || approvedRequest.getRenterID() == rejectedRequest.getRenterID())){
                    rejectedRequest.setRejected(true);
                    rejectedRequestList.push_back(rejectedRequest);
                }
            }
            break;
        }
    }

    ifstream request("request.txt");

    if (request.is_open()){
        int temp, requestID, renterID, day_rent;
        string bikeID, myString, line;
        bool isApproved;
        bool isRejected = false;

        while(getline(request, line)){
            stringstream ss(line);
            getline(ss, myString, ',');
            requestID = stoi(myString);
            getline(ss, myString, ',');
            renterID = stoi(myString);
            getline(ss, bikeID, ',');
            getline(ss, myString, ',');
            day_rent = stoi(myString);
            getline(ss, myString, ',');
            temp = stoi(myString);

            if (temp == 0){
                isApproved = false;
            } else {
                isApproved = true;
            }

            Request newRequest(requestID, renterID, bikeID, day_rent, isApproved, isRejected);
            
            for (Request reject : rejectedRequestList){
                if (newRequest.getRequestID() == reject.getRequestID()){
                    newRequest.setRejected(true);
                }
            }

            ifstream file("new.txt");
            if (file.is_open()){
                ofstream file("new.txt", ios::app);
                file << "\n" << newRequest.toString();
            } else {
                ofstream file("new.txt", ios::app);
                file << newRequest.toString();
            }
        }
        request.close();
    }

    remove("request.txt");
    rename("new.txt", "request.txt");

}


//list of rented bike
void Member::getRentedBike(){
    vector<Request> requests = requestList();
    vector<Motorbike> motorbikes = motorbikeList();
    Motorbike rentedMotor;

    for (Motorbike motor : motorbikes){
        for (Request request : requests){
            if (request.getRenterID() == this->id && request.getBikeID() == motor.getID() && request.getStatus()) {
                rentedMotor = motor;
                cout<<"-------------------MOTORBIKE INFORMATION---------------------------\n";
                motor.showinfo();
                
                string choice;
                cout<<"Do you want to return this bike? (y/n): ";
                cin.ignore();
                getline(cin, choice);

                if(choice == "y"){
                    cout<<"Please rating this motorbike (leave score and comment): \n";
                    this->ratingBike(motor.getID());
                }
            } else if (request.getRenterID() == this->id && request.getBikeID() == motor.getID() && request.getReject()){
                cout<<"Your request to bike "<< request.getBikeID() <<" with request id: " << to_string(request.getRequestID()) << " is rejected! \n";
            }
        }
    }
}
