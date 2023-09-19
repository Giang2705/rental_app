#include <iostream>
#include <fstream>
#include <string>
#include "Member.h"
#include "Rating.h"
using namespace std;

Member::Member(int id, string name, string username, string password, string phoneNumber, string idType, string idNumber, string driverLicense, string expiredDate) {
    this->id = id; 
    this->name = name; 
    this->username = username; 
    this->password = password; 
    this->phoneNumber = phoneNumber;
    this->idType = idType;
    this->idNumber = idNumber;
    this->driverLicense = driverLicense;
    this->expiredDate = expiredDate;}
Member::Member(){};

void Member::showInfo(){
    cout<<"Member Id: "<< id <<"\n";
    cout<<"Member's name: "<<name<<"\n\n"; 
}

void Member::rating(Member owner){
    int score;
    string cmt;
    
    cout<<"Enter score: ";
    cin>>score;
    cout<<"Enter comment: ";
    cin.ignore();
    getline(cin, cmt);

    Rating newRating(1, this->id, owner.id, score, cmt);
    owner.userRatingList.push_back(newRating);

    ifstream file("rating.txt");
    if (file.is_open()){
        ofstream file("rating.txt", ios::app);
        file << "\n" << newRating.getID() << "," << newRating.getCustomerID() << "," << newRating.getOwnerID() 
        << "," << newRating.getScore() << "," << newRating.getCmt();
    } else {
        ofstream file("rating.txt", ios::app);
        file << newRating.getID() << "," << newRating.getCustomerID() << "," << newRating.getOwnerID() 
        << "," << newRating.getScore() << "," << newRating.getCmt();
    }

    file.close();
}

void Member::showRatingList(){
    for (int i = 0; i<ratingList().size(); i++){
        if(ratingList()[i].getOwnerID() == this->id){
            this->userRatingList.push_back(ratingList()[i]);
        }
    }

    for (int i = 0; i < this->userRatingList.size(); i++){
        userRatingList[i].displayDetail();
        cout<<"----------\n";
    }
}

void Member::setScore(){
    double total = 0;

    for (int i = 0; i < this->userRatingList.size(); i++){
        total += userRatingList[i].getScore();
    }

    this->ratingScore = (total/userRatingList.size());
}

double Member::getScore(){
    return this->ratingScore;
}

string Member::getUsername() const {
    return username;
}

// Check if provided password matches the stored password
bool Member::checkPassword(const std::string& passwordInput) const {
    return passwordInput == this->password;
}


vector<Member> customerDatabase;    // This is a test database

// Function to register a new customer
void Member::registerCustomer() {
    
    int id = generateId();

    string name;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    
    string username;
    cout << "Enter your username: ";
    cin >> username;

    string password;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("users.txt");
    if (file.is_open()){
        ofstream file("users.txt", ios::app);
        file << "\n" << name << "," << username << ","<< password;
    } else {
        ofstream file("users.txt");
        file << name << "," << username << ","<< password;
    }
    file.close();

    // // Create a new Member object and add it to the customer database
    // Member newCustomer(id, name, {}, username, password);
    // customerDatabase.push_back(newCustomer);

    cout << "Registration successful. Your ID is: " << id << endl;
}

Member* loginCustomer(const std::string& usernameInput, const std::string& passwordInput) {
    for (Member& customer : customerDatabase) {
        if (customer.getUsername() == usernameInput && customer.checkPassword(passwordInput)) {
            cout << "Login successful. Welcome, " << customer.getUsername() << "!" << endl;
            return &customer;
            break;
        }
    }
    cout << "Login failed. Member ID not found." << endl;
    return nullptr;
}
