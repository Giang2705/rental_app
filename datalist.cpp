#include <iostream>
#include <string>
#include "datalist.h"
#include "Member.h"
#include "Rating.h"
using namespace std;

datalist::datalist(vector<Member> memberList, vector<Rating> ratingList){this->memberList = memberList; this->ratingList = ratingList;}

void datalist::addMember(Member member){
    this->memberList.push_back(member);
}

void datalist::addRating(Rating rating){
    this->ratingList.push_back(rating);
}

void datalist::showMemberList(){
    for (int i = 0; i < this->memberList.size(); i++){
        this->memberList[i].showInfo();
    }
}

void datalist::showMemberList(){
    for (int i = 0; i < this->ratingList.size(); i++){
        this->ratingList[i].displayDetail();
    }
}