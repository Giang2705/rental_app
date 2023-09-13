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
    public:
        Member(int id, string name, vector<Rating> ratingList);

        void showInfo();
        void rating(Member owner);
        void displayListRating();
};

#endif