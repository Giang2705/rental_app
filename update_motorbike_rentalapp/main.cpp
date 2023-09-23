#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

#include "Member.h"
#include "Rating.h"
#include "Motorbike.h"
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
        cout << "7. View motorbike rating list" << endl;
        cout << "8. View own rating list" << endl;
        cout << "9. Log out" << endl;
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
                    cout<<"-------------------MOTORBIKE INFORMATION---------------------------\n";
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
            cout<<"-------------------MOTORBIKE INFORMATION---------------------------\n";
            member.showSuitableBikes();
        } else if (choice == 4) {
            Request newRequest;

            cout<<"-------------------MOTORBIKE INFORMATION---------------------------\n";
            member.showSuitableBikes();

            newRequest.addNewRequest(member);

        } else if (choice == 5) {
            member.showRequest();
        } else if (choice == 6) {   
            member.getRentedBike();
        } else if (choice == 7) { 
            member.showBikeRatingList();
        } else if (choice == 8) { 
            member.showOwnRatingList();
        } else if (choice == 9) { 
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void adminScreen(){
    int option;
    while (true) {
        cout << "--------ADMIN MANAGEMENT-----------\n";
        cout << "Choose an option: " << endl;
        cout << "1. View all motorbikes" << endl;
        cout << "2. View all users" << endl;
        cout << "3. Exit" << endl;
        cout << "---------------------------------------\n";
        cout << "Enter option: ";
        cin >> option;

        if (option == 1){
            vector<Motorbike> motorbikes = motorbikeList();
            cout<<"--------------MOTORBIKES INFORMATION-----------------\n";
            for (Motorbike motor : motorbikes){
                motor.showinfo();
            }
        } else if (option == 2){
            vector<Member> memberlist = memberList();
            cout<<"--------------MEMBERS INFORMATION-----------------\n";
            for (Member member : memberlist){
                member.showInfo();
            }
        } else if (option == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main(){
    while (true){
        int choice;

        cout<<"\n-----------------------------------------------------\n";
        cout<<"|            EEET2482/COSC2082 ASSIGNMENT             |\n";
        cout<<"|            MOTORBIKE RENTAL APPLICATION             |\n\n";
        cout<<"|   Instructor: Dr. Ling Huo Chong                    |\n";
        cout<<"|   Group: Group 8                                    |\n";
        cout<<"|   1. s3877039, Student name: Thang Nguyen           |\n";
        cout<<"|   2. s3914108, Student name: Giang Nguyen           |\n";
        cout<<"|   3. s3986878, Student name: Anh Phung              |\n";
        cout<<"|   4. s3979297, Student name: Thao Trinh             |\n";
        cout<<"\n\n---------------------------------------------------\n\n";
        cout<<"Use the app as:  1.Guest     2.Member      3.Admin      4.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice == 1){

            while(true) {
                int option;

                cout << "--------MOTORBIKE RENTAL APP-----------\n";
                cout << "Choose an option: " << endl;
                cout << "1. View all motorbikes" << endl;
                cout << "2. Register" << endl;
                cout << "3. Login" << endl;
                cout << "4. Exit" << endl;
                cout << "---------------------------------------\n";
                cout << "Enter option: ";
                cin >> option;

                if (option == 1){
                    vector<Motorbike> motorbikes = motorbikeList();
                    cout<<"--------------MOTORBIKES INFORMATION-----------------\n";
                    for (Motorbike motor : motorbikes){
                        motor.showinfo();
                    }
                } else if (option == 2) {
                    Member newMember;
                    newMember.registerCustomer();
                } else if (option == 3) {
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
                } else if (option == 4) {
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
                
        } else if (choice == 2){
            while (true)
            {
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
                        }
                    }
                }
                break;
            }
            
        } else if (choice == 3){
            while (true) {
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
                } else {
                    for (Member i : memberList()){
                        if (i.getUsername() == username){
                            member = i;
                            break;
                        }
                    }
                    if (member.admin()){
                        adminScreen();
                    } else {
                        cout<<"You are not admin!\n";
                    }
                    break;
                }
            }
        } else if (choice == 4) {
            break;  
        } else {
            cout << "Invalid choice. Please try again" << endl;
        }
    }

    return 0;
}