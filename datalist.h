#ifndef _DATALIST_H_
#define _DATALIST_H_

#include <iostream>
#include <vector>
#include "Member.h"
#include "Rating.h"

using namespace std;

class datalist {
    private:
        vector<Member> memberList;
        vector<Rating> ratingList;
    public:
        datalist();
        datalist(vector<Member> memberList ,vector<Rating> ratingList);

        void addMember(Member member);
        void addRating(Rating rating);
        void showMemberList();
        void showRatingList();
};

#endif