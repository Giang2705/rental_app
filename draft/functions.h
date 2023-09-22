#ifndef _FUNC_H_
#define _FUNC_H_

#include "Member.h"
#include "Rating.h"
#include "Motorbike.h"
#include "Request.h"
#include <iostream>
#include <vector>
using namespace std;

int generateId(vector<Member> memberList);
vector<Rating> ratingList();
vector<Member> memberList();
vector<Motorbike> motorbikeList();
vector<Request> requestList();

#endif