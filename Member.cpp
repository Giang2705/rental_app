#include <iostream>
#include <fstream>
#include <string>
#include "Member.h"
#include "Rating.h"
using namespace std;

Member::Member(int id, string name, string username, string password) {this->id = id; this->name = name; this->username = username; this->password = password;}
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

    Rating newRating(1, this->name, owner.name, score, cmt);

    this->ratingList.push_back(newRating);
}

void Member::displayListRating(){
    for (int i = 0; i < this->ratingList.size(); i++){
        this->ratingList[i].displayDetail();
    }
}

vector<Rating> Member::getRatingList(){
    return this->ratingList;
}

string Member::getUsername() const {
    return username;
}

// Check if provided password matches the stored password
bool Member::checkPassword(const std::string& passwordInput) const {
    return passwordInput == this->password;
}


// Function to register a new customer
void Member::registerCustomer() {
    string fullname, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate;
    int id = generateId();
    int creditPoint = 20;

    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, fullname);
    
    cout << "Enter your phone number: ";
    cin.ignore();
    getline(cin, phoneNumber);

    cout << "Enter your ID type (passport / ID): ";
    cin.ignore();
    getline(cin, idType);

    cout << "Enter your ID Number (passport / ID): ";
    cin.ignore();
    getline(cin, idNumber);

    cout << "Enter your driver license: ";
    cin.ignore();
    getline(cin, driverLicense);

    cout << "Enter the expired date of your driver license: ";
    cin.ignore();
    getline(cin, expiredDate);

    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, username);
// There is a need to check for the same account

    cout << "Enter your password: ";
    cin.ignore();
    getline(cin, password);

    ifstream file("users.txt");
    if (file.is_open()){
        ofstream file("users.txt", ios::app);
        file << "\n" << id << fullname << "," << username << ","<< password << "," << creditPoint << ","<< phoneNumber << ","<< idType << ","<< idNumber << ","<< driverLicense << ","<< expiredDate;
    } else {
        ofstream file("users.txt");
        file << id << fullname << "," << username << ","<< password << "," << creditPoint << ","<< phoneNumber << ","<< idType << ","<< idNumber << ","<< driverLicense << ","<< expiredDate;
    }
    file.close();

    // // Create a new Member object and add it to the customer database
    // Member newCustomer(id, name, {}, username, password);
    // customerDatabase.push_back(newCustomer);

    cout << "Registration successful!!!! " << "\n" << fullname << "\nYour ID : " << id <<
    "\nYour credit point: "<< creditPoint << endl;
}


vector<Member> readDatabase(){
    ifstream inputFile("users.txt");
    vector<Member> members; 
   
    int id;
    string name, username, password;
    while (inputFile >> id >> name >> username >> password) {
        members.emplace_back(id, name, username, password);
    }

    inputFile.close();
    return members;
}

Member* loginCustomer(const std::string& usernameInput, const std::string& passwordInput, vector<Member>& members) {
    for (Member& customer : members) {
        if (customer.getUsername() == usernameInput && customer.checkPassword(passwordInput)) {
            cout << "Login successful. Welcome, " << customer.getUsername() << "!" << endl;
            return &customer;
            break;
        }
    }
    cout << "Login failed. Member ID not found." << endl;
    return nullptr;
}
