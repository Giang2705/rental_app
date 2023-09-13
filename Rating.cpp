#include <iostream>
#include "Rating.h"
#include "Member.h"
using namespace std;

Rating::Rating(int id, string customer, string owner, int score, string cmt) {this->id = id; this->customer = customer; this->owner = owner ;this->score = score, this->cmt = cmt;}

void Rating::displayDetail(){
    cout<<"Owner's information: "<<owner<<"\n";
    cout<<"Customer's information: "<<customer<<"\n";
    cout<<"Rating Id: "<< id <<"\n";
    cout<<"Rating's score: "<<score<<"\n";
    cout<<"Rating's comment: "<<cmt<<"\n\n";
}