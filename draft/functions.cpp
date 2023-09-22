#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include "functions.h"

using namespace std;

int generateId(vector<Member> memberList){
    int id;
    vector<int> v(memberList.size());
    random_device rd;
    iota(v.begin(), v.end(), 1);
    for (auto i : v){
        if (memberList.size() == i) {
            id = i+1;
            break;
        }
    }
    return id;
};

vector<Rating> renterRatingList(){
    vector<Rating> renterRatingList = {};

    ifstream renterRating("renterRating.txt");
    if(renterRating.is_open()){
        int customerID, ownerID, id, score;
        string cmt, myString, line;

        while(getline(renterRating, line)){
            stringstream ss(line);
            getline(ss, myString, ',');
            id = stoi(myString);
            getline(ss, myString, ',');
            customerID = stoi(myString);
            getline(ss, myString, ',');
            ownerID = stoi(myString);
            getline(ss, myString, ',');
            score = stoi(myString);
            getline(ss, cmt);


            Rating newRating(id, customerID, ownerID, score, cmt);
            renterRatingList.push_back(newRating);
        }

        renterRating.close();
    }

    return renterRatingList;
};

vector<Member> memberList(){
    vector<Member> memberList = {};

    ifstream members("users.txt");
    if(members.is_open()){
        int id;
        string name, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate, myString, line;
        double ratingScore, creditPoint;

        while(getline(members, line)){
            stringstream ss(line);
            getline(ss, myString, ',');
            id = stoi(myString);
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

            Member newMember(id, name, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate, ratingScore, creditPoint);
            memberList.push_back(newMember);
        }

        members.close();
    }

    return memberList;
};

vector<Motorbike> motorbikeList(){
    vector<Motorbike> motorbikeList;

    ifstream motor("motorbikes.txt");
    if(motor.is_open()){
        int ownerID, temp;
        double requiredScore, motorbike_rating_score, credit;
        string bikeID, brand, model, color, city, description, engine_size, myString, line;
        bool isRented;

        while(getline(motor, line)){
            stringstream ss(line);
            getline(ss, myString, ',');
            ownerID = stoi(myString);
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

            Motorbike newMotor(ownerID, bikeID, city, requiredScore, isRented, motorbike_rating_score, credit, brand, model, color, description, engine_size);
            motorbikeList.push_back(newMotor);
        }

        motor.close();
    }

    return motorbikeList;
};

// vector<Request> requestList(){
//     vector<Request> requestList;

//     ifstream rating("rating.txt");
//     if(rating.is_open()){
//         int customerID, ownerID, id, score;
//         string cmt, myString, line;

//         while(getline(rating, line)){
//             stringstream ss(line);
//             getline(ss, myString, ',');
//             id = stoi(myString);
//             getline(ss, myString, ',');
//             customerID = stoi(myString);
//             getline(ss, myString, ',');
//             ownerID = stoi(myString);
//             getline(ss, myString, ',');
//             score = stoi(myString);
//             getline(ss, cmt);


//             Rating newRating(id, customerID, ownerID, score, cmt);
//             ratingList.push_back(newRating);
//         }

//         rating.close();
//     }

//     return requestList;
// };
