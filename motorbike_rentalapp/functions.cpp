#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include "functions.h"

using namespace std;

// Automatically generating ID
int generateId(vector<Member> memberList){
    int id;    // Creating a random number 
    vector<int> v(memberList.size());
    random_device rd;
    iota(v.begin(), v.end(), 1);
    for (auto i : v){
        if (memberList.size() == i) {
            id = i+1;    // Calculating order to ID
            break;
        }
    }
    return id;
};

vector<Rating> renterRatingList(){
    vector<Rating> renterRatingList = {};    // Creating an empty vector of Rating objects.

    ifstream renterRating("renterRating.txt");
    if(renterRating.is_open()){    // Taking the data if the file is successfully opened.
        int customerID, ownerID, id, score;
        string cmt, myString, line;

        // Read the file line by line.
        while(getline(renterRating, line)){
            stringstream ss(line);    // Create a stringstream to parse the line.

            // Parse the comma-separated values from the line and convert them to appropriate data types.
            getline(ss, myString, ',');
            id = stoi(myString);    // Convert to double using stod.
            getline(ss, myString, ',');
            customerID = stoi(myString);
            getline(ss, myString, ',');
            ownerID = stoi(myString);
            getline(ss, myString, ',');
            score = stoi(myString);
            getline(ss, cmt);

            // Create a new Rating object using the parsed data and add it to the renterRatingList vector.
            Rating newRating(id, customerID, ownerID, score, cmt);
            renterRatingList.push_back(newRating);
        }

        renterRating.close();
    }

    return renterRatingList;
};

vector<Member> memberList(){
    vector<Member> memberList = {};    // Create an empty vector of Member objects.

    ifstream members("users.txt");
    if(members.is_open()){     // Taking the data if the file is successfully opened.
        int id;
        string name, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate, myString, line;
        double ratingScore, creditPoint;

        // Read the file line by line.
        while(getline(members, line)){
            stringstream ss(line);    // Create a stringstream to parse the line.

            // Parse the comma-separated values from the line and convert them to appropriate data types.
            getline(ss, myString, ',');
            id = stoi(myString);    // Convert to double using stod.
            getline(ss, name, ',');
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, idType, ',');
            getline(ss, idNumber, ',');
            getline(ss, driverLicense, ',');
            getline(ss, expiredDate, ',');
            getline(ss, myString, ',');
            ratingScore = stoi(myString);    
            getline(ss, myString, ',');
            creditPoint = stoi(myString);

            // Create a new Member object using the parsed data and add it to the memberList vector.
            Member newMember(id, name, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate, ratingScore, creditPoint);
            memberList.push_back(newMember);
        }

        members.close();
    }

    return memberList;
};

vector<Motorbike> motorbikeList(){
    vector<Motorbike> motorbikeList;    // Create an empty vector of Motorbike objects.

    ifstream motor("motorbikes.txt");
    if(motor.is_open()){    // Taking the data if the file is successfully opened.
        int ownerID, temp;
        double requiredScore, motorbike_rating_score, credit;
        string bikeID, brand, model, color, city, description, engine_size, myString, line;
        bool isRented;

        // Read the file line by line.
        while(getline(motor, line)){
            stringstream ss(line);    // Create a stringstream to parse the line.

            // Parse the comma-separated values from the line and convert them to appropriate data types.
            getline(ss, myString, ',');
            ownerID = stoi(myString);    // Convert to double using stod.
            getline(ss, bikeID, ',');
            getline(ss, city, ',');
            getline(ss, brand, ',');
            getline(ss, model, ',');
            getline(ss, color, ',');
            getline(ss, engine_size, ',');
            getline(ss, description, ',');
            getline(ss, myString, ',');
            credit = stoi(myString);
            getline(ss, myString, ',');
            requiredScore = stoi(myString);
            getline(ss, myString, ',');
            temp = stoi(myString);

            if (temp == 0){
                isRented = false;
            } else {
                isRented = true;
            }

             // Create a new Motorbike object using the extracted data and add it to the motorbikeList vector.
            Motorbike newMotor(ownerID, bikeID, city, requiredScore, isRented, motorbike_rating_score, credit, brand, model, color, description, engine_size);
            motorbikeList.push_back(newMotor);
        }

        motor.close();
    }

    return motorbikeList;
};

vector<Request> requestList(){
    vector<Request> requestList;    // Create an empty vector of Request objects.

    ifstream request("request.txt");
    if(request.is_open()){     // Taking the data if the file is successfully opened.
        int requestID, renterID, day_rent, temp;
        string bikeID, myString, line;
        bool isApprove;

        // Read the file line by line.
        while(getline(request, line)){
            stringstream ss(line);    // Create a stringstream to parse the line.

            // Parse the comma-separated values from the line and convert them to appropriate data types.
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
                isApprove = false;
            } else {
                isApprove = true;
            }

            // Create a new Request object using the extracted data and add it to the requestList vector.
            Request newRequest(requestID, renterID, bikeID, day_rent, isApprove);
            requestList.push_back(newRequest);
        }

        request.close();
    }

    return requestList;
};
