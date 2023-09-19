#include <iostream>
#include <string>
#include "Member.h"
#include "Rating.h"
using namespace std;

Member::Member(int id, string name, vector<Rating> ratingList) {
    this->id = id; this->name = name; this->ratingList = ratingList;
}

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