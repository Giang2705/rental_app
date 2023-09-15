#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <iostream>
#include <vector>
#include <string>
#include "functions.h"
#include "datalist.h"
#include "Rating.h"

using namespace std;

class Member {
    private:
        int id;
        string name;
        vector<Rating> ratingList;
        string username;
        string password;
    public:
        Member(int id, string name, vector<Rating> ratingList, string username, string password);

        void showInfo();
        void rating(Member owner);
        void displayListRating();
        vector<Rating> getRatingList();

        string getUsername() const;
        bool checkPassword(const std::string& passwordInput) const;
};

void registerCustomer();
Member* loginCustomer(const std::string& usernameInput, const std::string& passwordInput);

#endif