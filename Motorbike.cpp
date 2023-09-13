class Motorbike{
    private:
    int bikeID;
    string brand;
    string city;
    int requiredScore;
   bool isRented = 0;
   vector <Motorbike *> motorlist;
   public:
   Motorbike(int bikeID = 0, string city = "", int requiredScore = 0, bool isRented = false, vector <Motorbike*> motorlist = {}) 
            : bikeID(bikeID), city(city), requiredScore(requiredScore), isRented(isRented), motorlist(motorlist){} 
    
    string toString(){
        return "Bike ID: " + to_string(bikeID) + "\n" + "Brand: " + brand + "\n" + "City: " + city + "\n" + "Required Score: " + to_string(requiredScore) + "\n";
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
            cout << "Please enter the brand of bike: ";
            cin.ignore();
            getline(cin, brand);
            cout << "Enter city: ";
            cin.ignore();
            getline(cin, city);
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
    
};
