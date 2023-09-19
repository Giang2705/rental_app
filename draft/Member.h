#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <iostream>
#include <vector>
#include <string>
#include "functions.h"
#include "Rating.h"

using namespace std;

class Member {
    private:
        int id, creditPoint;
        double ratingScore;
        string name, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate;
        vector<Rating> userRatingList;
    public:
        Member(int id, string name, string username, string password, string phoneNumber, string idType, string idNumber, string driverLicense, string expiredDate);
        Member();

        void showInfo();
        void showRatingList();
        void rating(Member owner);
        void setScore();
        double getScore();
        void registerCustomer();
        Member* loginCustomer(const std::string& usernameInput, const std::string& passwordInput);

        string getUsername() const;
        bool checkPassword(const std::string& passwordInput) const;
};

#endif