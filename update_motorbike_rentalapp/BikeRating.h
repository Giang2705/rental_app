#ifndef _BIKE_RATING_H_
#define _BIKE_RATING_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//declare class BikeRating
class BikeRating {
    private:
        // attributes
        int customerID;
        double score;
        string bikeID, cmt;
    public:
        // declare functions
        BikeRating(int customerID, string bikeID, double score, string cmt);
        BikeRating();

        double getScore();
        string getBikeID();
        int getCustomerID();
        string getCmt();

        void setScore(double score);
        void setBikeID(string bikeID);
        void setCustomerID(int cusID);
        void setCmt(string cmt);

        void displayDetail();
};

#endif
