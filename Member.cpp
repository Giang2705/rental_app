#include <iostream>
#include <fstream>
#include <sstream>
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

string Member::getPassword() {
    return password;
}

// Function to register a new customer
void Member::registerCustomer() {
    vector<Member> members = Member::readDatabase();
    int id = generateId();
    int creditPoint = 20;

    string fullname;
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, fullname);
    
    string phoneNumber;
    cout << "Enter your phone number: ";
    cin.ignore();
    getline(cin, phoneNumber);

    string idType;
    cout << "Enter your ID type (passport / ID): ";
    cin.ignore();
    getline(cin, idType);

    string idNumber;
    cout << "Enter your ID Number (passport / ID): ";
    cin.ignore();
    getline(cin, idNumber);

    string driverLicense;
    cout << "Enter your driver license: ";
    cin.ignore();
    getline(cin, driverLicense);

    string expiredDate;
    cout << "Enter the expired date of your driver license: ";
    cin.ignore();
    getline(cin, expiredDate);

    string username;
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, username);
    // Checking existing account
    for (Member& member : members){
        while (member.getUsername() == username)
        {
            cout << "The username has existed ,enter another username: ";
            getline(cin, username);
        }
    }

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


vector<Member> Member::readDatabase(){
    ifstream inputFile("users.txt");
    vector<Member> members; 

    // Create a vector to store the data from the file
    vector<vector<string>> data;

    // Read the data from the file line by line
    string line;
    while (getline(inputFile, line)) {
        // Split the line into columns
        vector<string> columns;
        istringstream ss(line);
        string column;
        while (getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Add the columns to the data vector
        data.push_back(columns);
    }

    // Close the file
    inputFile.close();

    // Iterate over the data vector and create a Member object for each row
    for (vector<string>& row : data) {
        // Get the id, name, username, and password from the row
        int id = std::stoi(row[0]);
        string name = row[1];
        string username = row[2];
        string password = row[3];

        // Create a new Member object and add it to the members vector
        Member member(id, name, username, password);
        members.push_back(member);
    }

    return members;
}

Member *Member::loginCustomer(const string& username, const string& password)
{
    vector<Member> members = Member::readDatabase();

    for (Member& member : members) {
        if (member.getUsername() == username && member.getPassword() == password) {
            return &member;
        }
    }
    return nullptr;
}
