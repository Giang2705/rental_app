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
    public:
        Request(int requestID, int renterID, string bike_rented_ID, int day_rented, bool isApproved);
        
        int getRenterID();
        int getBikeID();
        bool getStatus();

        void addNewRequest();
        void approveRequest();
};

#endif