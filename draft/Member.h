#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <iostream>
#include <vector>
#include <string>
#include "Rating.h"

using namespace std;

class Member {
    private:
        int id;
        double ratingScore, creditPoint;
        string name, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate;
        vector<Rating> userRatingList;
    public:
        Member(int id, string name, string username, string password, string phoneNumber, string idType, string idNumber, string driverLicense, string expiredDate, double ratingScore, double creditPoint);
        Member();

        int getID();
        string getName();
        string getUsername();
        string getPassword();

        void showInfo();
        void showRatingList();
        void ratingRenter(Member renter);
        void setScore();
        double getScore();
        void registerCustomer();
        Member* loginCustomer(const std::string& usernameInput, const std::string& passwordInput);
        void showSuitableBikes();
};

#endif