#include <iostream>
using namespace std;

#include "Member.h"
#include "Rating.h"
#include "datalist.h"
#include "functions.h"

int main(){
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

    return 0;
}