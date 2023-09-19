#include <iostream>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

#include "Member.h"
#include "Rating.h"
#include "functions.h"

int main(){
    Member mem2(2, "member 1", "username1", "123455", "0909123456", "passport", "C0213321", "B12334", "02/26");
    Member mem4(4, "member 2", "username2", "4657687", "0909123456", "passport", "C0213321", "B12334", "02/26");

    mem2.rating(mem4);
    mem4.rating(mem2);

    mem2.rating(mem4);
    mem4.rating(mem2);

    mem2.rating(mem4);
    mem4.rating(mem2);

    for (int i = 0; i<ratingList().size(); i++){
            ratingList()[i].displayDetail();
            cout<<"----------\n";
    }

    cout<<"Rating list of mem 2: \n";
    mem2.showRatingList();
    cout<<"-------------------\n";

    cout<<"Rating list of mem 4: \n";
    mem4.showRatingList();

    mem2.setScore();
    mem4.setScore();

    cout<<"mem2's score: "<<mem2.getScore()<<"\n";
    cout<<"mem4's score: "<<mem4.getScore();
    
    return 0;
}