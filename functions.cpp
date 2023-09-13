#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "functions.h"
using namespace std;

int generateId(){
    int id;
    vector<int> v(10);
    random_device rd;
    iota(v.begin(), v.end(), 1);
    for (auto i : v){
        id = i;
        break;
    }
    return id;
};