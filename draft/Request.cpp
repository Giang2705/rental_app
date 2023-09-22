#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Rating.h"
#include "Member.h"
#include "Motorbike.h"
#include "Request.h"
#include "functions.h"

using namespace std;

Request::Request(int ID, int renterID, string bikeID, int day_rent, bool isApproved) {
        this->requestID = ID;
        this->renterID = renterID;
        this->bike_rented_ID = bikeID;
        this->day_rented = day_rent;
        this->isApproved = isApproved;
}

Request::Request(){

}

string Request::display()
{
    return "Request ID: " + to_string(requestID) + "\nBike ID: " + bike_rented_ID + "\nRenter: " + to_string(renterID) + "\nStatus:" + to_string(isApproved) + "\n";

}

string Request::toString()
{
    return to_string(requestID) + "," + to_string(renterID) + "," + bike_rented_ID + "," + to_string(day_rented) + "," + to_string(isApproved);
}

int Request::getRenterID() {
    return this->renterID;
}

string Request::getBikeID(){
    return this->bike_rented_ID;
}

bool Request::getStatus(){
    return this->isApproved;
}

void Request::addNewRequest(Member member){
    vector<Request> requestlist = requestList();
    string bikeID;
    cout << "Please enter license plate: ";
    cin >> bikeID;
    bool isRented = false;

    for (Request request: requestlist){
        if(request.getBikeID() == bikeID && request.isApproved){
            cout << "Bike already exist" << endl;
            isRented = true;
            break;
        }
    }

    if (isRented){
        return;
    } else {
        cout << "Enter day rent: ";
        cin >> day_rented;

        Request newRequest(member.getID(), 1, bikeID, day_rented, false);

        ifstream file("request.txt");
            if (file.is_open()){
            ofstream file("request.txt", ios::app);
            file << "\n" << newRequest.toString();
        } else {
            ofstream file("request.txt", ios::app);
            file << newRequest.toString();
        }
        file.close();

        requestlist.push_back(newRequest);
        cout << "Added successfully" << endl;   
    } 
}    

// string renter_info(Member &renter, Motorbike bike) {
//     string reString = "";

//     reString = "Request ID: " + to_string(requestID) + "Bike ID: " + to_string(bike.get_bikeID()) + "Renter: " + to_string(renter.id) + "\nRating: ";
//     for (int i = 0; i < renter.ratingList.size(); i++) {
//         reString = reString + renter.ratingList[i].displayDetail();
//     }

//     return reString;
// }

//     void save_request(Member &renter, Motorbike bike, string renter_info)
//     {
//         fstream myfile;
//         int ownerID;

//         for (int i = 0; i < motorlist.size(); i++)
//         {
//             if (motorlist[i]->get_bikeID() == bike.get_bikeID())
//             {
//                 ownerID = motorlist[i]->get_userID();
//             }
//             else
//             {
//                 cout << "Unvalid input of bikeID!";
//             }
//         }

//         string filename = to_string(ownerID) + "_request.dat";
//         myfile.open(filename, ios::out);
//         if (!myfile.is_open())
//         {
//             cout << "Can't find the file related to " << filename << " yet" << endl;
//         }
//         myfile >> renter_info;

//         string text = "";
//         while (myfile.peek() != EOF)
//         {
//             getline(myfile, text);
//             get_text.push_back(text);
//         }
//         myfile.close();
//     }

//     void confirm_request(Motorbike bike) // execute when user chose to view requests
//     {
//         int ownerID;
//         string filename = to_string(ownerID) + "_request.dat";

//         for (int i = 0; i < motorlist.size(); i++)
//         {
//             if (motorlist[i]->get_bikeID() == bike.get_bikeID())
//             {
//                 ownerID = motorlist[i]->get_userID();
//             }
//             else
//             {
//                 cout << "Unvalid input of bikeID!";
//             }
//         }
//         // when user open file to see who has requested their bike
//         ifstream myfile1;
//         string text = "";

//         myfile1.open(filename);
//         if (!myfile1.is_open())
//         {
//             cout << "Can't find the file related to " << filename << " yet" << endl;
//         }

//         if (!get_text.empty()) // true if vector size is 0, false otherwise
//             for (int i = 0; i < get_text.size(); i++)
//             {
//                 cout << get_text[i];
//             }
//         else
//             cout << "Request list is empty.\n";

//         string ans;
//         int num;
//         int userID;
//         int bikeID;
//         fstream myfile;
//         while (num != 0)
//         {
//             cout << "Do you want to approve any request? ('1' for yes / '0' for no): ";
//             cin >> num;
//             if (num == 1)
//             {
//                 cout << "Enter the bikeID you want to approve: ";
//                 cin >> bikeID;
//                 cout << "Enter the bikeID you want to approve: ";
//                 cin >> userID;

//                 for (int i = 0; i < motorlist.size(); i++)
//                 {
//                     if (motorlist[i]->get_bikeID() == bikeID)
//                     {
//                         motorlist[i]->set_isRented(true);
//                         // cần add renter ID vô rent.cpp
//                         myfile.open(filename, ios::out);

//                         for (int i = 0; i < get_text.size(); i++)
//                         {
//                             if (get_text[i] == to_string(bikeID))
//                                 get_text.erase(get_text.begin() + i);
//                             myfile.close();
//                         }
//                     }
//                     else
//                     {
//                         cout << "Unvalid input of bikeID!";
//                     }
//                 }
//             }
//             else if (num == 0)
//             {
//                 break;
//             }
//             else
//             {
//                 cout << "invalid input!";
//             }
//         }
//     }
