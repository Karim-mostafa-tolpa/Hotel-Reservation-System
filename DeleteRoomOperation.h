


#ifndef DELETEROOMOPERATION_H
#define DELETEROOMOPERATION_H

#include <vector>
#include "Room.h"
#include "Reservation.h"
using namespace std;

class DeleteRoomOperation {
    vector<Room>& rooms;
    vector<Reservation>& reservations;
public:
    DeleteRoomOperation(vector<Room>& r, vector<Reservation>& res);
    void execute();
};

#endif