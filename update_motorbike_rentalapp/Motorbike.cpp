#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include "Motorbike.h"
#include "Member.h"
#include "functions.h"
#include <math.h>

using namespace std;
// default constructor
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
// default constructor
Motorbike::Motorbike(){

}
// structures:
void Motorbike::setOwnerID(Member member){
    this->ownerID = member.getID();
}

int Motorbike::getOwnerID(){
    return this->ownerID;
}

double Motorbike::getCredit(){
    return this->credit;
}

double Motorbike::getRequiredScore(){
    return this->requiredScore;
}

string Motorbike::getID(){
    return this->bikeID;
}

bool Motorbike::isRent(){
    return this->isRented;
}

void Motorbike::setRented(bool isRent){
    this->isRented = isRent;
}

string Motorbike::toString()
{
    return to_string(ownerID) + "," + bikeID + "," + city + "," + brand + "," + model + "," + color + "," + engine_size + "," + description + "," + to_string(round(credit)) + "," + to_string(round(requiredScore)) + "," + to_string(round(motorbike_rating_score)) + "," + to_string(isRented);
}

// find motorbike and indicate if it is existed
string Motorbike::findbike(string ID){
    vector<Motorbike> motorlist = motorbikeList();
    for(int i = 0; i < motorlist.size(); i++){
        if(motorlist[i].bikeID == ID){
            return motorlist[i].bikeID;
        }
    }
    return "";
}

// add motorbike to user account where existed motorbike will not be valid to be added
void Motorbike::addbike(Member member)
{
    vector<Motorbike> motorlist = motorbikeList();
    string bikeID;
    string a = "Ha Noi";
    string b = "Sai Gon";
    int index = 1;
    cout << "Please enter license plate: ";
    cin >> bikeID;
    cin.ignore(1, '\n');

    string findbikeID = findbike(bikeID);  // used the findbike function to know if the bike is already existed
    if (findbikeID != "")
    {
        cout << "Bike already exist" << endl;
    }
    else
    {
        while (index != 0)
        {
            cout << "Enter city: ";
            getline(cin, city);

            if (city.compare(a) == 0 || city.compare(b) == 0) //the application is only available in Sai Gon and Ha Noi so others city will not be allow
            {
                break;
            }
            else if (city.compare(a) != 0 || city.compare(b) != 0)
            {
                cout << "The application is only available to users in Ha Noi and Sai Gon!" << endl;
            }
        }

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

        while (index != 0)
        {
            cout << "Enter required score: ";
            cin >> requiredScore;
            if (requiredScore <= 10 && requiredScore >= 0) // rating score must be a number from 1 to 10
            {
                break;
            }
            else
            {
                cout << "The required score must be from 0 to 10!" << endl;
            }
        }
    }

    Motorbike newMotor(member.getID(), bikeID, city, requiredScore, false, 0, credit, brand, model, color, description, engine_size);
    newMotor.setOwnerID(member);

    savebike(newMotor, "motorbikes.txt"); //save the new bike into the system file

    motorlist.push_back(newMotor);
    cout << "Added successfully" << endl;
}
 
// remove a bike function
void Motorbike::removebike(Motorbike motorbike){
        ifstream motor("motorbikes.txt");

        if (motor.is_open()){ // open the motorbike file
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

// presenting information of the bike
void Motorbike::showinfo(){
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

// function to save new bike into the system file
void Motorbike::savebike(Motorbike newMotor, string filename){
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
