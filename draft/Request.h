#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <iostream>
#include <vector>
#include "Member.h"

using namespace std;

class Request {
    private:
        int requestID;
        int renterID;
        string bike_rented_ID;
        int day_rented;
        bool isApproved;
    public:
        Request(int requestID, int renterID, string bike_rented_ID, int day_rented, bool isApproved);
        Request();
        string toString();
        string display();

        int getRenterID();
        string getBikeID();
        bool getStatus();

        void addNewRequest(Member member);
        void approveRequest();
};

#endif