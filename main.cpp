#include <iostream>
using namespace std;

#include "Member.h"
#include "Rating.h"
#include "datalist.h"
#include "functions.h"
#include "Motorbike.h"

int main(){
    int character_choice;
    cout << "Use the app as:" << endl;
    cout << "1. Guest" << endl;
    cout << "2. Member" << endl;
    cout << "3. Admin" << endl;
    cout << "Enter your choice: ";
    cin >> character_choice;
    
    switch(character_choice){
        case 1:
        system("CLS");
        int guest_choice;
        cout << "1. Sign up" << endl;
        cout << "2. View" << endl;
        cout << "Enter your choice: ";
        cin >> guest_choice;
        if(guest_choice == 1){
            
        }else if(guest_choice == 2){
            Motorbike showbike();
        }

        case 2:
        system("CLS");
        int member_choice;
        cout << "1. View profile: " << endl;
        cout << "2. View motorbike list" << endl;
        cout << "3. View request" << endl;
        cout << "4. Rent motorbike" << endl;
        cin >> member_choice;

        case 3: 
        system("CLS");
        datalist showMemberList();

    }

    datalist datalist;
    Member mem1(generateId(), "member 1", {});
    Member mem2(generateId(), "member 2", {});

    datalist.addMember(mem1);
    datalist.addMember(mem2);

    datalist.showMemberList();

    int choose;
    do {
        cout<<"Enter choose: ";
        cin>>choose;
        if (choose != 1) {
            break;
        } else {
            mem1.rating(mem2);
        }
    } while (choose == 1);

    mem1.displayListRating();

    for (int i = 0; i < mem1.getRatingList().size(); i++){
        datalist.addRating(mem1.getRatingList()[i]);
    }

    datalist.showRatingList();

    return 0;
}