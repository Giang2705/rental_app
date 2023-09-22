#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

#include "Member.h"
#include "Rating.h"
#include "Motorbike.h"
#include "Request.h"
#include "functions.h"

void userScreen(Member member){
    int choice;

    cout<<"------------------Hello "<< member.getName() << "-----------------------\n";
    while (true) {
    cout << "--------------MEMBER MENU--------------\n";
    cout << "Choose an option: " << endl;
    cout << "1. Add a motorbike to available rental list" << endl;
    cout << "2. View and modify own motorbike" << endl;
    cout << "3. View all suitable bike(s)" << endl;
    cout << "4. Request to rent a motorbike" << endl;
    cout << "5. View all requests to all own motorbike" << endl;
    cout << "6. View rented motorbike" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------------------\n";
    cout << "Enter choice: ";
    cin >> choice;

        if (choice == 1) {
            Motorbike newMotor;
            newMotor.addbike(member);
        } else if (choice == 2) {
            vector<Motorbike> motorbikes = motorbikeList();
            bool isFound = false;

            for (Motorbike motor: motorbikes) {
                if (motor.getOwnerID() == member.getID()){
                    motor.showinfo();

                    string choice;
                    cout<<"Do you want to delete this bike? (y/n): ";
                    cin.ignore();
                    getline(cin,choice);

                    if(choice == "y"){
                        motor.removebike(motor);
                    }

                    isFound = true;
                    break;
                }
            }

            if (!isFound){
                cout<<"There is no motorbike found!\n";
            }

        } else if (choice == 3) {
            member.showSuitableBikes();
        } else if (choice == 4) {
            Request newRequest;

            member.showSuitableBikes();
            newRequest.addNewRequest(member);

        } else if (choice == 5) {
            for (Request request : member.showRequest()){
                request.display();
                cout<<"________________\n";
            }

        } else if (choice == 6) {
            member.showSuitableBikes();
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void adminScreen(){

}

int main(){
    int choice;
    while (true) {
        cout << "--------MOTORBIKE RENTAL APP-----------\n";
        cout << "Choose an option: " << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "---------------------------------------\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Member newMember;
            newMember.registerCustomer();
        } else if (choice == 2) {
            string username, password;

            cout <<"----------------LOGIN---------------\n";
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            cout<<"-------------------------------------\n";
            
            Member member;
            Member* hasLogin = member.loginCustomer(username, password);
            if (hasLogin == nullptr){
                cout << "Login failed." << endl;
            }else{
                for (Member member : memberList()){
                    if (member.getUsername() == username){
                        userScreen(member);
                        break;
                    }
                }
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}