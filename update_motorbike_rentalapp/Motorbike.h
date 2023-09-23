#ifndef _MOTORBIKE_H_
#define _MOTORBIKE_H_

#include <iostream>
#include <vector>
#include <fstream>
#include "Member.h"

using namespace std;

class Motorbike{
    private:
        int ownerID;
        string bikeID;
        double requiredScore;
        bool isRented;
        double motorbike_rating_score;
        double credit;
        string brand;
        string model;
        string color;
        string city;
        string description;
        string engine_size;
    public:
        Motorbike(int ownerID, string bikeID, string city, double requiredScore, bool isRented, double motorbike_rating_score, double credit, string brand, string model, string color, string description, string engine_size);
        Motorbike();

        string getID();
        void setOwnerID(Member member);
        int getOwnerID();
        double getRequiredScore();
        double getCredit();
        bool isRent();
        void setRented(bool isRent);

        string toString();
        string findbike(string ID);
        void addbike(Member member);
        void removebike(Motorbike motor);    
        void showinfo();
        void savebike(Motorbike newMotor, string filename);
};

#endif