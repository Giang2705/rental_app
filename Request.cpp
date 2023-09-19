#include <iostream>
#include <vector>
#include <fstream>
#include "Member.h"
#include "Motorbike.h"

using namespace std;

class Request
{
private:
    int requestID;
    vector<Member *> renter;
    vector<Motorbike *> motorlist;

public:
    Request(int ID = 0, vector<Member *> renter = {}, vector<Motorbike *> bike = {})
    {
        this->requestID = ID;
        this->renter = renter;
        this->motorlist = bike;
    }

    string renter_info(Member &renter, int bikeID)
    {

        return "Renter: " + to_string(renter.id) + "\nRating: ";
        for (int i = 0; i < renter.ratingList.size(); i++)
        {
            renter.ratingList[i].displayDetail();
        }
    }

    void save_request(Member &renter, int bikeID, string renter_info)
    {
        fstream myfile;
        int ownerID;

        for (int i = 0; i < motorlist.size(); i++)
        {
            if (motorlist[i]->get_bikeID() == bikeID)
            {
                ownerID = motorlist[i]->get_userID();
            }
            else
            {
                cout << "Unvalid input of bikeID!";
            }
        }

        string filename = to_string(ownerID) + "_request.dat";
        myfile.open(filename, ios::out);
        if (!myfile.is_open())
        {
            cout << "Can't find the file related to " << filename << " yet" << endl;
        }
        myfile >> renter_info;
        myfile.close();
    }

    void confirm_request(int bikeID)
    {
        int ownerID;
        string filename = to_string(ownerID) + "_request.dat";

        for (int i = 0; i < motorlist.size(); i++)
        {
            if (motorlist[i]->get_bikeID() == bikeID)
            {
                ownerID = motorlist[i]->get_userID();
            }
            else
            {
                cout << "Unvalid input of bikeID!";
            }
        }
        // when user open file to see who has requested their bike
        ifstream myfile1;
        string text;

        myfile1.open(filename);
        if (!myfile1.is_open())
        {
            cout << "Can't find the file related to " << filename << " yet" << endl;
        }

        while (getline(myfile1, text))
        {
            // Output the text from the file
            cout << text;
        }
        myfile1.close();

        string ans;
        int userID;
        while (ans[0] != 'Q')
        {
            cout << "Enter the userID you want to approve: ";
            cin >> userID;
        }
    }
};

int main()
{
    Member one(3, "thao", {}, " ", " ");
    Request two;
    // two.send_request(one);
}
