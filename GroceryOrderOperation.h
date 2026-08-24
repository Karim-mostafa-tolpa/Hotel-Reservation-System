


#ifndef GROCERYORDEROPERATION_H
#define GROCERYORDEROPERATION_H

#include <vector>
#include "Room.h"
#include "Reservation.h"
#include "User.h"
using namespace std;

class GroceryOrderOperation {
    vector<Room>& rooms;
    vector<Reservation>& reservations;
    User& currentUser;
public:
    GroceryOrderOperation(vector<Room>& r, vector<Reservation>& res, User& u);
    void execute();
};

#endif