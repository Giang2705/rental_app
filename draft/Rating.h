#ifndef _RATING_H_
#define _RATING_H_

#include <iostream>
#include <vector>
#include <string>
// #include "functions.h"

using namespace std;

class Rating {
    private:
        int customerID, ownerID, id, score;
        string cmt;
    public:
        Rating(int id, int customer, int owner, int score, string cmt);
        int getCustomerID();
        int getOwnerID();
        int getID();
        int getScore();
        string getCmt();
        void displayDetail();
};

#endif