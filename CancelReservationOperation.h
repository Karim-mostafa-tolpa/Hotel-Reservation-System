

#ifndef CANCELRESERVATIONOPERATION_H
#define CANCELRESERVATIONOPERATION_H

#include <vector>
#include "Room.h"
#include "Reservation.h"
#include "User.h"
using namespace std;

class CancelReservationOperation {
    vector<Room>& rooms;
    vector<Reservation>& reservations;
    User& currentUser;
public:
    CancelReservationOperation(vector<Room>& r, vector<Reservation>& res, User& u);
    void execute();
};

#endif