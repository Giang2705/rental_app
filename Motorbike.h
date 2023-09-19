#ifndef _MOTORBIKE_H_
#define _MOTORBIKE_H_

#include <iostream>
#include <vector>
#include <fstream>
#include "Motorbike.h"
using namespace std;
#define MOTORBIKE "Motorbike.dat"

class Motorbike{
    private:
    int bikeID;
    int requiredScore;
    bool isRented = 0;
    int motorbike_rating_score;
    int credit;
    string brand;
    string model;
    string color;
    string city;
    string description;
    string engine_size;
   vector <Motorbike *> motorlist;
   public:
   Motorbike(int bikeID = 0, string city = "", int requiredScore = 0, bool isRented = false, vector <Motorbike*> motorlist = {}, int motorbike_rating_score = 0,int credit = 0, string brand = "", string model = "", string color = "", string description = "", string engine_size = "") 
            : bikeID(bikeID), city(city), requiredScore(requiredScore), isRented(isRented), motorlist(motorlist), motorbike_rating_score(motorbike_rating_score), credit(credit), brand(brand), model(model), color(color), description(description), engine_size(engine_size){} 

    string toString(){
        return "Bike ID: " + to_string(bikeID) + "\n" + "City: " + city + "\n" + "Brand: " + brand + "\n" + "Model: " + model + "\n" +"Color: " + color + "\n" + "Engine size: " + engine_size + "\n" + "Description: " + description + "\n" + "Credit: " + to_string(credit) + "\n" + "Required Score: " + to_string(requiredScore) + "\n";
    }

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
            cout << "Enter city: ";
            cin.ignore();
            getline(cin, city);
            cout << "Please enter the brand of bike: ";
            cin.ignore();
            getline(cin, brand);
            cout << "Please enter model of bike: ";
            cin.ignore();
            getline(cin, model);
            cout << "Please enter the color of bike: ";
            cin.ignore();
            getline(cin, color);
            cout << "Please enter the engine size: ";
            cin.ignore();
            getline(cin, engine_size);
            cout << "Please enter description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Please enter credit of bike: ";
            cin >> credit;
            cout << "Enter required score: ";
            cin >> requiredScore;

            motorlist.push_back(&addbike);
            cout << "Added successfully" << endl;
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

    void showinfo(){
        for(Motorbike* i : motorlist){
            cout << i->toString();
        }
    }

    void savebike(){
        ofstream outfile;
        if(!motorlist.empty()){
            outfile.open(MOTORBIKE);
                if(!outfile){
                    cerr << "Problem with the file.\n";
                }else{
                    for(auto i : motorlist){
                        outfile << i->toString();
                    }
                    outfile.close();
                    cout << "Motorbike list is saved" << endl;
                }
        }else{
            cout << "Motorbike list is empty";
        }
    }
};

#endif
