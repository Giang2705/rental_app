#include <iostream>
#include <iostream>
using namespace std;

#include "Member.h"
#include "Rating.h"
#include "functions.h"

int main(){

    int choice;
    string username, password;
    Member* loggedInCustomer = nullptr;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Member newMember;
            newMember.registerCustomer();
        } else if (choice == 2) {
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            
            Member member;
            Member* hasLogin = member.loginCustomer(username, password);
            if (hasLogin == nullptr){
                cout << "Login failed." << endl;
            }else{
                cout << "Login as: " << username << endl;
                 //     // Displaying Motobikes 

            //     int choose;
            //     do {
            //         cout<<"Enter choose: ";
            //         cin>>choose;
            //         if (choose != 1) {
            //             break;
            //         } else {
            //             mem1.rating(mem2);
            //         }
            //     } while (choose == 1);

            //     mem1.displayListRating();
            
            // }
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}