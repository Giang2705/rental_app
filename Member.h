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
        int id, creditPoint, ratingScore;
        vector<Rating> ratingList;
        string name, username, password, phoneNumber, idType, idNumber, driverLicense, expiredDate;
    
    public:
        Member(int id, string name, string username, string password);
        Member();

        void showInfo();
        void rating(Member owner);
        void displayListRating();
        vector<Rating> getRatingList();
        vector<Member> readDatabase();
        void registerCustomer();
        Member* loginCustomer(const std::string& usernameInput, const std::string& passwordInput);

        string getUsername() const;
        bool checkPassword(const std::string& passwordInput) const;
};

#endif