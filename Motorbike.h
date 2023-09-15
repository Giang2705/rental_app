#ifndef _MOTORBIKE_H_
#define _MOTORBIKE_H_

#include <iostream>
#include <vector>
#include <Member.h>
using namespace std;

class Motorbike{
    private:
    int bikeID;
    string brand;
    Member userID;
    string city;
    int requiredScore;
   bool isRented = 0;
   vector <Motorbike *> motorlist;
   public:
   Motorbike(int bikeID = 0, Member userID = 0, string city = "", int requiredScore = 0, bool isRented = false, vector <Motorbike*> motorlist = {}) 
            : bikeID(bikeID), userID(userID), city(city), requiredScore(requiredScore), isRented(isRented), motorlist(motorlist){} 
    
    int findbike(int ID){
        for(int i = 0; i < motorlist.size(); i++){
            if(motorlist[i]->bikeID == ID){
                return i;
            }
        }
        return -1;
    }


    void addbike(Motorbike &addbike){
        int bikeID;
        cout << "Please enter license plate: ";
        cin >> bikeID;

        int findbikeID = findbike(bikeID);
        if (findbikeID != -1)
        {
            cout << "Bike already exist" << endl;
        }else{
            cout << "Please enter the brand of bike: ";
            cin.ignore();
            getline(cin, brand);
            cout << "Enter city: ";
            cin.ignore();
            cin >> city;
            cout << "Enter required score: ";
            cin >> requiredScore;

            motorlist.push_back(&addbike);
        }
    }

    void removebike(){
        // int bikeID;
        cout << "Please enter license plate: ";
        cin >> bikeID;
        int removeind = findbike(bikeID);

        if(removeind != -1){
            motorlist.erase(motorlist.begin() + removeind);
            cout << "Remove successfully";
        }else{
            cout << "Bike not found";
        }
    }
};

#endif
