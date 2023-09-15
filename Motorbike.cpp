#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define FILENAME "member.dat" //data file

class Member{
    private:
    int userID;
    string username_mem;
    string password_mem;
    public:
    Member(int userID = 0, string username_mem = "", string password_mem = "") : userID(userID), username_mem(username_mem), password_mem(password_mem){}

    string getusername_mem(){
        return username_mem;
    }
};

class Admin{
    private:
    string username_admin;
    string password_admin;
    vector <Member> memberlist;
    public:
    Admin(string username_admin = "", string password_admin = "", vector <Member> memberlist = {}) : username_admin(username_admin), password_admin(password_admin), memberlist(memberlist){}

};

class Non_member{
    private:
    string username_re;
    string fullname;
    int phone_num;
    string ID_type;
    int ID_num;
    int drive_license;
    string expiry_date; //nghien cuu them data datatype
    vector <Member> memberlist;
    public:
    Non_member(string username_re = "", string fullname = "", int phone_num = 0, string ID_type = "", int ID_num = 0, int drive_license = 0, string expiry_date = "", vector <Member> memberlist)
    : username_re(username_re), fullname(fullname), phone_num(phone_num), ID_type(ID_type), ID_num(ID_num), drive_license(drive_license), expiry_date(expiry_date), memberlist(memberlist){}

    int findmember(string username){
        for(int i = 0; i < memberlist.size(); i++){
            if(memberlist[i].getusername_mem() == username){
                return i;
            }
        }
        return -1;
    }

    void memRegister(){
        // cout << "Enter fullname ";
        // cin >> fullname;
        cout << "Enter username: ";
        cin >> username_re;

        int finduser = findmember(username_re);
            if(finduser != -1){

            }
    };

};

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


    void addbike(){
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

            //motorlist.push_back(bikeID, brand, city, requiredScore);
        }
    }

};

class Request{
    private:
    string username;
    Motorbike bikeID;
    
};
