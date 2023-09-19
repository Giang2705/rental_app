#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include "functions.h"

using namespace std;

int generateId(){
    int id;
    vector<int> v(10);
    random_device rd;
    iota(v.begin(), v.end(), 1);
    for (auto i : v){
        id = i;
        break;
    }
    return id;
};

vector<Rating> ratingList(){
    vector<Rating> ratingList;

    ifstream rating("rating.txt");
    if(rating.is_open()){
        int customerID, ownerID, id, score;
        string cmt, myString, line;

        while(getline(rating, line)){
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
            ratingList.push_back(newRating);
        }

        rating.close();
    }

    return ratingList;
};
