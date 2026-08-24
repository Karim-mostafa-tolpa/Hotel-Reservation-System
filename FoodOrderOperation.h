

#ifndef FOODORDEROPERATION_H
#define FOODORDEROPERATION_H

#include <vector>
#include "Room.h"
#include "Reservation.h"
#include "User.h"
using namespace std;

//كلاس عشان طلب الاكل 

class FoodOrderOperation {
    vector<Room>& rooms;
    vector<Reservation>& reservations;
    User& currentUser;
public:
    FoodOrderOperation(vector<Room>& r, vector<Reservation>& res, User& u);
    void execute();
};

#endif