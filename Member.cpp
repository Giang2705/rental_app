#include <iostream>
#include <fstream>
#include <string>
#include "Member.h"
#include "Rating.h"
using namespace std;

Member::Member(int id, string name, vector<Rating> ratingList, string username, string password) {this->id = id; this->name = name; this->ratingList = ratingList; this->username = username; this->password = password;}
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
