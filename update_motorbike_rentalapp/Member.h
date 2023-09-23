#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <iostream>
#include <vector>
#include <string>
#include "Rating.h"
#include "BikeRating.h"

using namespace std;

//declare class Member
class Member {
    private:
    //attributes
        int id;
        double ratingScore, creditPoint;
        string name, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate;
        vector<Rating> userRatingList;
        bool isAdmin;
    public:

        // constructors
        Member(int id, string name, string username, string password, string phoneNumber, string idType, string idNumber, string driverLicense, string expiredDate, double ratingScore, double creditPoint, bool isAdmin);
        Member();

        //setter getter and functions
        int getID();
        string getName();
        string getUsername();
        string getPassword();
        bool admin();

        void showInfo();
        void ratingRenter(Member renter);
        void ratingBike(string bikeID);
        void showBikeRatingList();
        void showOwnRatingList();
        void setScore();
        double getScore();
        void registerCustomer();
        Member* loginCustomer(const std::string& usernameInput, const std::string& passwordInput);
        void showSuitableBikes();
        void showRequest();
        void approveRequest(int requestID);
        void rejectRequest();
        void getRentedBike();

};

#endif
