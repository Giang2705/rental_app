#ifndef _RATING_H_
#define _RATING_H_

#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

class Rating {
    private:
        string customer;
        string owner;
        int id, score;
        string cmt;
    public:
        Rating(int id, string customer, string owner, int score, string cmt);
        void displayDetail();
};

#endif