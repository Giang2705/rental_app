#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <iostream>
#include <vector>
#include "Member.h"
#include "Motorbike.h"

using namespace std;

class Request {
    private:
        int requestID;
        int renterID;
        string bike_rented_ID;
        int day_rented;
        bool isApproved;
        bool isRejected;
    public:
        Request(int requestID, int renterID, string bike_rented_ID, int day_rented, bool isApproved, bool isRejected);
        Request();
        string toString();
        string display();

        int getRenterID();
        string getBikeID();
        bool getStatus();
        bool getReject();
        int getRequestID();
        void setApprove(bool isApproved);
        void setRejected(bool isRejected);

        void addNewRequest(Member member);
};

#endif

