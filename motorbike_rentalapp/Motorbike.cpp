#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Motorbike.h"
#include "Member.h"
#include "functions.h"

using namespace std;

//Parameterized constructor
Motorbike::Motorbike(int ownerID, string bikeID, string city, double requiredScore, bool isRented, double motorbike_rating_score, double credit, string brand, string model, string color, string description, string engine_size){
    this->ownerID = ownerID;
    this->bikeID = bikeID;
    this->city = city;
    this->requiredScore = requiredScore;
    this->isRented = isRented;
    this->motorbike_rating_score = motorbike_rating_score;
    this->credit = credit;
    this->brand = brand;
    this->model = model;
    this->color = color;
    this->description = description;
    this->engine_size = engine_size;
}

Motorbike::Motorbike(){ //Default Constructor with no parameter

} 

void Motorbike::setOwnerID(Member member){ //set memberID to ownerID
    this->ownerID = member.getID();
}

int Motorbike::getOwnerID(){ //get ownerID
    return this->ownerID;
}

double Motorbike::getCredit(){ //get credit point
    return this->credit;
}

double Motorbike::getRequiredScore(){ //get required score
    return this->requiredScore;
}

string Motorbike::getID(){ //get the bikeID
    return this->bikeID;
}

bool Motorbike::isRent(){ //boolean to indetify whether the motorbike is rented
    return this->isRented;
}

string Motorbike::toString() 
{
    return to_string(ownerID) + "," + bikeID + "," + city + "," + brand + "," + model + "," + color + "," + engine_size + "," + description + "," + to_string(credit) + "," + to_string(requiredScore) + "," + to_string(motorbike_rating_score) + "," + to_string(isRented);
}

string Motorbike::findbike(string ID){ //function to find motorbike
    vector<Motorbike> motorlist = motorbikeList();
    for(int i = 0; i < motorlist.size(); i++){
        if(motorlist[i].bikeID == ID){
            return motorlist[i].bikeID;
        }
    }
    return "";
}

void Motorbike::addbike(Member member){ //function to add motorbike
    vector<Motorbike> motorlist = motorbikeList();
    string bikeID;
    cout << "Please enter license plate: ";
    cin >> bikeID;

    string findbikeID = findbike(bikeID); //find motorbike at first to distinguish whether the motorbike exist or not
    if (findbikeID != "") {
        cout << "Bike already exist" << endl;
    } else {
        cout << "Enter city: ";
        cin.ignore();
        getline(cin, city);
        cout << "Please enter the brand of bike: ";
        getline(cin, brand);
        cout << "Please enter model of bike: ";
        getline(cin, model);
        cout << "Please enter the color of bike: ";
        getline(cin, color);
        cout << "Please enter the engine size: ";
        getline(cin, engine_size);
        cout << "Please enter description: ";
        getline(cin, description);
        cout << "Please enter credit of bike: ";
        cin >> credit;
        cout << "Enter required score: ";
        cin >> requiredScore;        

        Motorbike newMotor(member.getID(), bikeID, city, requiredScore, false, 0, credit, brand, model, color, description, engine_size);
        newMotor.setOwnerID(member);

        savebike(newMotor, "motorbikes.txt");

        motorlist.push_back(newMotor);
        cout << "Added successfully" << endl;
    }            
}    

void Motorbike::removebike(Motorbike motorbike){ //function to remove motorbike
        ifstream motor("motorbikes.txt");

        if (motor.is_open()){
            int temp;
            string myString, line;

            while(getline(motor, line)){
                stringstream ss(line);
                getline(ss, myString, ',');
                ownerID = stoi(myString);
                getline(ss, bikeID, ',');
                getline(ss, city, ',');
                getline(ss, brand, ',');
                getline(ss, model, ',');
                getline(ss, color, ',');
                getline(ss, engine_size, ',');
                getline(ss, description, ',');
                getline(ss, myString, ',');
                credit = stoi(myString);
                getline(ss, myString, ',');
                requiredScore = stoi(myString);
                getline(ss, myString, ',');
                temp = stoi(myString);

                if (temp == 0){
                    isRented = false;
                } else {
                    isRented = true;
                }

                Motorbike newMotor(ownerID, bikeID, city, requiredScore, isRented, motorbike_rating_score, credit, brand, model, color, description, engine_size);

                if (newMotor.bikeID != motorbike.bikeID){
                    savebike(newMotor, "new.txt");
                } else {
                    
                }
            }
            motor.close();
        }

        cout<<"Motorbike is removed!\n";
        remove("motorbikes.txt");
        rename("new.txt", "motorbikes.txt");
}      

void Motorbike::showinfo(){ //show information of the motorbike
        cout<<"-------------------MOTORBIKE INFORMATION---------------------------\n";
        cout<<"Owner's ID: "<< this->ownerID << "\n";
        cout<<"Bike's ID: "<< this->bikeID << "\n";
        cout<<"Brand: "<< this->brand << "\n";
        cout<<"Model: "<< this->model << "\n";
        cout<<"Color: "<< this->color << "\n";
        cout<<"Engine size: "<< this->engine_size << "\n";
        cout<<"Description: "<< this->description << "\n";
        cout<<"Credit points: "<< this->credit << "\n";
        cout<<"Required rating score: "<< this->requiredScore << "\n";
        cout<<"Rating score: "<< this->motorbike_rating_score << "\n";
        cout<<"Rented: "<< this->isRented << "\n";
        cout<<"_____________\n";
}    

void Motorbike::savebike(Motorbike newMotor, string filename){ //save the motorbike to list
    ifstream file(filename);
    if (file.is_open()){
        ofstream file(filename, ios::app);
        file << "\n" << newMotor.toString();
    } else {
        ofstream file(filename, ios::app);
        file << newMotor.toString();
    }
    file.close();
}        
